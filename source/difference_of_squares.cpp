#include "difference_of_squares.h"
#include <cmath>


namespace squares
{
int square_of_sums(const int n)
{
    int sum = 0;
    for (int i=1; i<=n; ++i)
        sum += i;
    return pow(sum,2);
}

int sum_of_squares(const int n)
{
    int sum = 0;
    for (int i=1; i<=n; ++i)
        sum += pow(i,2);
    return sum;
}

int difference (const int n)
{
    auto diff = square_of_sums(n) - sum_of_squares(n);
    return diff;
}
}
