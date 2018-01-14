#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H
#include <algorithm>
#include <numeric>
#include <vector>


namespace sum_of_multiples
{

int to(const std::vector<int>& multiples_of, const int up_to)
{
    std::vector<int> accepted_numbers;
    for (int i=0; i<multiples_of.size(); ++i)
        for (int j=1; j<up_to/multiples_of[i]+1; ++j)
        {
            int current = j*multiples_of[i];
            if (current<up_to && std::find(accepted_numbers.begin(), accepted_numbers.end(), current) == accepted_numbers.end())
                accepted_numbers.push_back(current);
        }
    return std::accumulate(accepted_numbers.begin(), accepted_numbers.end(), 0);
}

}

#endif
