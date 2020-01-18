#include "jung.h"
#include <stdio.h>
#include <iostream>
#include <unordered_map>

#include "jung.h"

using namespace std;

void jung_main(int argc, char** argv){
    printf("This is Jung's Main\n");
    unordered_map<char, double> energyMap;
    energyMap.insert({'N', 10});
    energyMap.insert({'S', 10});
    energyMap.insert({'W', 10});
    energyMap.insert({'H', 10});
    energyMap.insert({'C', 10});
    energyMap.insert({'G', 10});
    energyMap.insert({'B', 10});
    double result = total_cost(energyMap);
    printf("result :%f", result);
}

double total_cost(unordered_map<char, double> energyMap){
    double sum = 0;
    unordered_map<char, double> :: iterator itr;
    // Iterate through the map to identify which part of the energy it belongs to
    for (itr = energyMap.begin(); itr != energyMap.end(); itr++)
    {
        double value = itr->second;
        if (itr->first == 'N'){
            sum += value * NUCLEAR_C;
        } else if (itr->first == 'S'){
            sum += itr->second * SOLAR_C;
        } else if (itr->first == 'W'){
            sum += itr->second * WIND_C;
        } else if (itr->first == 'H'){
            sum += itr->second * HYDRO_C;
        } else if (itr->first == 'C'){
            sum += itr->second * COAL_C;
        } else if (itr->first == 'G'){
            sum += itr->second * GEO_C;
        } else if (itr->first == 'B'){
            sum += itr->second * NEIGHBOUR_C;
        } else {
            return -1;
        }
    }
    
    return sum;
}
