#if !defined(GRAINS_H)
#define GRAINS_H
#include <cmath>


namespace grains {

unsigned long long square(const unsigned int& n)
{
    if (n == 1)
        return 1;
    else
        return std::pow(2, n - 1);
}


unsigned long long total(const unsigned int& n)
{
   if (n == 1)
       return 1;
   else
       return static_cast<unsigned long long>(std::pow(2, n - 1)) + total(n - 1);
}


unsigned long long total()
{
    return total(64);
    //unsigned long long sum = 0;
    //for (auto i = 64; i >= 1; --i)
    //        sum += static_cast<unsigned long long>(std::pow(2, i-1));
    //return sum;
}

}
#endif
