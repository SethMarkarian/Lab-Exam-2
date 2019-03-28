#include "timegenerator.h"

TimeGenerator::TimeGenerator(std::string _filename, int _seed)
{
    seed = _seed;

    //reading the file
    int content;
    std::ifstream file;
    file.open(_filename);
    if(!file) {
        std::cout <<"Can't open file";
        exit(1);
    }
    while(!file.eof()) {
        file >> content;
        lambda.push_back(content);
    }
    file.close();
}

void TimeGenerator::generate()
{
    std::default_random_engine generator(seed);
    for(int i = 0; i < lambda.size(); i++) {
        std::binomial_distribution<int> binDist(lambda.at(i), 0.7);
        int k = binDist(generator);
        for(int j = 0; i < k; i++) {
            std::exponential_distribution<double> expDist(k);
            times.push_back(expDist(generator));
        }
    }
}

std::string TimeGenerator::print_times()
{
    std::string ret = "";
    for(int i = 0; i < times.size(); i++) {
        ret += std::to_string(times.at(i));
    }
    return ret;
}
