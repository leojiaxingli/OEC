#include "joanna.h"
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, double> carbon;  
    

void joanna_main(int argc, char** argv){
    //initialize global var carbon
    
       
    unordered_map<char, double> amounts;
    //sample test
    double carbonAmount = co2Grams(amounts);

    return;
    
}

double co2Grams(unordered_map<char, double> amounts) {
    carbon['N'] = 6000;
    carbon['S'] = 105000;
    carbon['W'] = 13000;
    carbon['H'] = 4000;
    carbon['C'] = 909000;
    carbon['G'] = 58000;
    carbon['B'] = 258000;
    unordered_map<char, double>::iterator it;
    double totalGrams = 0;
    for (it = amounts.begin(); it != amounts.end(); it++) {
        char energyType = it->first;
        totalGrams += it->second*carbon[energyType];
    }
    return totalGrams;
}
