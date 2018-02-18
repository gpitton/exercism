#if !defined(GRAINS_H)
#define GRAINS_H
#include <cmath>
#include <cstdint>



namespace grains {


uint_fast64_t square(const unsigned int& n)
{
    if (n == 1)
        return 1;
    else
        return std::pow(2, n - 1);
}



uint_fast64_t total(const unsigned int& n)
{
   if (n == 1)
       return 1;
   else
       return static_cast<uint_fast64_t>(std::pow(2, n - 1)) + total(n - 1);
}


uint_fast64_t total()
{
    return total(64);
    //uint_fast64_t sum = 0;
    //for (auto i = 64; i >= 1; --i)
    //        sum += static_cast<uint_fast64_t>(std::pow(2, i-1));
    //return sum;
}

}
#endif
