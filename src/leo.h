#ifndef LEO_H
#define LEO_H

#include <vector>
#include <string>
#include <unordered_map>
std::unordered_map<char,double> get_capacity(std::vector<std::string> row);
void leo_main(int, char**);
std::vector<std::vector<std::string> > read_CSV(std::string);
void write_CSV(std::vector<std::vector<std::string> >,std::string);
#endif /* LEO_H */

