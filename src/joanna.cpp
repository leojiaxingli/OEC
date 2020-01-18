#include "joanna.h"
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, double> carbon;  
    

void joanna_main(int argc, char** argv){
    //initialize global var carbon
    carbon['N'] = 6;
    carbon['S'] = 105;
    carbon['W'] = 13;
    carbon['H'] = 4;
    carbon['C'] = 909;
    carbon['G'] = 58;
    carbon['B'] = 258;
       
    unordered_map<char, double> amounts;
    //sample test
    double carbonAmount = co2Grams(amounts);

    return;
    
}

double co2Grams(unordered_map<char, double> amounts) {
    unordered_map<char, double>::iterator it;
    double totalGrams = 0;
    for (it = carbon.begin(); it != carbon.end(); it++) {
        char energyType = it->first;
        totalGrams += amounts[energyType];
    }
    return totalGrams;
}
