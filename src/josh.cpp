#include "josh.h"
#include <stdio.h>

#define BREAK_TEMPERATURE 10.95

void josh_main(int argc, char** argv){
    printf("This is Joshua's Main\n");
}

// amounts contains the <key, value> pairs of all the 7 different types of energy
// and the amount that each one supplied for a given hour
double get_total_supplied(unordered_map <char, double> amounts) {
    double total = 0; // IN MW
    
    // Calculate total
    for (unordered_map <char, double>::iterator it = amounts.begin(); it != amounts.end(); ++it) {
        total = total + it->second;
    }
    return total;
}

// Assume average temperatures
// Assume summer months are May to October and winter months are November to April
double get_selling_cost(double temperature, int time) {
    double rate; // In dollars/MWh
    
    // Summer rate
    if (temperature > BREAK_TEMPERATURE) {
        // Assume time in 24h00 format and no invalid values are passed as parameters
        if ((time >= 700 && time < 1100) || (time >= 1700 && time < 1900)) {
            rate = 94;
        } else if (time >= 1100 && time < 1700) {
            rate = 134;
        } else {
            rate = 65;
        }
    // Winter rate
    } else {
        if ((time >= 700 && time < 1100) || (time >= 1700 && time < 1900)) {
            rate = 134;
        } else if (time >= 1100 && time < 1700) {
            rate = 94;
        } else {
            rate = 65;
        }
    }
    return rate;
}