#include "leo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
void leo_main(int argc, char** argv){
    printf("This is Leo's Main\n");
    vector<vector<string> > rows = read_CSV("test.csv");
    for(int i=0;i<rows.size();i++){
        for(int j=0;j<rows[i].size();j++){
            cout<<std::atoi(rows[i][j].c_str());
            if(j!=rows[i].size()-1){
                cout<<',';
            }
        }
        cout<<endl;
    }
    write_CSV(rows,"out.csv");
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
    }
    return rows;
}