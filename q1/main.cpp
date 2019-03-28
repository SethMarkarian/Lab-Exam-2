#include <iostream>
#include <random>
#include "timegenerator.h"

using namespace std;

int main()
{
    /*
    unsigned int seed = 12345; // This is a seed.
    std::default_random_engine generator(seed); // This is the RNG.

    // Now I make a binomial distribution with parameters n and p.
    unsigned int n = 20;
    double p = 0.7;
    std::binomial_distribution<unsigned int> binomDistbn(n, p);
    // Generate some binomial-distributed numbers.
    cout << binomDistbn(generator) << ", "
         << binomDistbn(generator) << ", "
         << binomDistbn(generator) << endl;

    // Now I make an exponential distribution with parameter m.
    double m = 20;
    std::exponential_distribution<double> expDistbn(m);
    // Generate some exponentially distributed numbers.
    cout << expDistbn(generator) << ", "
         << expDistbn(generator) << ", "
         << expDistbn(generator) << endl;
*/
    TimeGenerator tg = TimeGenerator("activityLevels.txt", 12345);
    tg.generate();
    cout << tg.print_times() << endl;

    return 0;
}
