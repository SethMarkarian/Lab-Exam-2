#ifndef TIMEGENERATOR_H
#define TIMEGENERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <random>

class TimeGenerator
{
private:
    std::vector<int> lambda;
    std::vector<double> times;
    int seed;
public:
    TimeGenerator(std::string _filename, int _seed);
    void generate();
    std::string print_times();
};

#endif // TIMEGENERATOR_H
