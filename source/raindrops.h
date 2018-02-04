#if !defined(RAINDROPS_H)
#define RAINDROPS_H
#include <map>
#include <string>


namespace raindrops {

std::string convert(const unsigned int& n)
{
    std::map<unsigned int, std::string> factor_word {{3, "Pling"}, {5, "Plang"}, {7, "Plong"}};
    std::string output = {};
    bool has_factors = false;

    for (auto it = factor_word.begin(); it != factor_word.end(); ++it)
        if (n % it->first == 0)
        {
            has_factors = true;
            output += factor_word[it->first];
        }

    if (has_factors)
        return output;
    else
        return std::to_string(n);
}

}
#endif
