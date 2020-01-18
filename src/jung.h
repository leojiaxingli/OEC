
#ifndef JUNG_H
#define JUNG_H
#include <unordered_map>

#define NUCLEAR_C 68;
#define SOLAR_C 481;
#define WIND_C 133;
#define HYDRO_C 57;
#define COAL_C 140;
#define GEO_C 131;
#define NEIGHBOUR_C 160;

void jung_main(int, char**);
double total_cost(std::unordered_map<char, double> energyMap);

#endif /* JUNG_H */

