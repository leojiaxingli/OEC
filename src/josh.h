#ifndef JOSH_H
#define JOSH_H

#include <unordered_map>
using namespace std;

void josh_main(int, char**);

double get_total_supplied(unordered_map <char, double> amounts);

double get_selling_cost(double temperature, int time);

#endif /* JOSH_H */

