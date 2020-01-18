#include "leo.h"
#include "joanna.h"
#include "jung.h"
#include "josh.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
void analyze(string file){
    vector<vector<string> > rows = read_CSV(file.c_str());
    vector<vector<string> > out_rows = vector<vector<string> >();
    double last_nuclear = 0;
    
    for(int i=0;i<rows.size();i++){
        if(i == 0){
            last_nuclear = std::atof(rows[i][4].c_str());
        }
        vector<string> result = analyze_row(rows[i],last_nuclear);
        if(std::atoi(rows[i][0].c_str())==0){
            
        }else{
            
            out_rows.push_back(result);
        }           
        last_nuclear = std::atof(result[4].c_str());
//        cout<<"last nuclear: "<<last_nuclear<<endl;
    }
    write_CSV(out_rows,"out.csv");
}
string to_string_auto(double num){
    std::ostringstream streamObj2;
    //streamObj2 << std::fixed;
    streamObj2 << num;
    return streamObj2.str();
}
vector<string> analyze_row(vector<string> row, double last_nuclear){
    vector<string> result = vector<string>();
    char order[] = {'C','B','S','G','W','N','H'};
    unordered_map<char,double> cap = get_capacity(row);    
    double demand = std::atof(row[2].c_str());
    
    cap['N'] = last_nuclear;
    
    int cut_order = 0;
    double supply = get_total_supplied(cap);
    
    double cut = supply - demand;
//    cout<<"before: "<<supply<<endl;
    while(cut>0){
        if(cut>cap[order[cut_order]]){
            cap[order[cut_order]] = 0;
            cut_order++;
        }else{
            cap[order[cut_order]]-=cut;
        }
        cut = get_total_supplied(cap) - demand;
    }
    
//    cout<<"after: "<<get_total_supplied(cap)<<endl;

    int counter =0;
    for (unordered_map <char, double>::iterator it = cap.begin(); it != cap.end(); ++it) {
//        cout<<it->first<<','<<it->second<<endl;
        counter ++;
    }
    
    result.push_back("2");
    result.push_back(row[1]);    
    result.push_back(to_string_auto(get_total_supplied(cap)));
    
    char out_order[] = {'S','N','W','H','C','G','B'};
    for(int i=0;i<counter;i++){
        result.push_back(to_string_auto(cap[out_order[i]]));
//        cout<<cap[out_order[i]]<<',';
    }
    result.push_back(to_string_auto(demand-get_total_supplied(cap)));
    result.push_back(to_string_auto(get_total_green(cap)));
    result.push_back(to_string_auto(cap['B']));//bought
    result.push_back(to_string_auto(0));//sold
    //bought
    //sold
    result.push_back(to_string_auto(co2Grams(cap)/1000000));
    istringstream iss(row[1]);
    string temp;
    
    int time = 0;
    while (getline(iss, temp, ':')) {
        time*=100;
        int num = atoi(temp.c_str());
        time+=num;
    }
//    cout<<"time: "<<time<<endl;
    result.push_back(to_string_auto(get_selling_cost(atof(row[10].c_str()),time)/1000));
    result.push_back(to_string_auto(total_cost(cap)/1000/get_total_supplied(cap)));
    result.push_back(to_string_auto(total_cost(cap)/1000/get_total_supplied(cap)-get_selling_cost(atof(row[10].c_str()),time)/1000));
    result.push_back(to_string_auto(-1));
    
    return result;
}
unordered_map<char,double> get_capacity(vector<string> row){
    unordered_map<char,double> capacity = unordered_map<char,double>();
    char key[] = {'S','N','W','H','C','G','B'};
    for(int i=3;i<=9;i++){
        float num = std::atof(row[i].c_str());
        capacity[key[i-3]] = num;
    }
    return capacity;
}
void leo_main(int argc, char** argv){
    if(argc!=2){
        cout<<"Usage: oec.exe file.csv"<<endl;
    }else{
        analyze(argv[1]);
    }
}
void write_CSV(vector<vector<string> > rows, string file){
    ofstream outfile(file.c_str());
    if(outfile){
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<rows[i].size();j++){
                outfile<<rows[i][j];
                if(j!=rows[i].size()-1){
                    outfile<<',';
                }
            }
            outfile<<endl;
        } 
    }
}
void split(const string& s,vector<string>& sv,const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(temp);
    }
    return;
}
vector<vector<string> > read_CSV(string file){
    vector<vector<string> > rows = vector<vector<string> >();
    string row;
    ifstream infile(file.c_str());
    if (infile.is_open()){
        //TODO encoding
        while(getline(infile,row)){            
            vector<string> row_split = vector<string>();
            split(row, row_split, ',');
            rows.push_back(row_split);
        }
    }else{
        cout<<"File "<<file<<" not found"<<endl;
    }
    return rows;
}