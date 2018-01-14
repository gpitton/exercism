#include "etl.h"
#include <locale>


namespace etl
{


std::map<char,int> transform(const std::map<int,std::vector<char>>& old_system)
{
    std::map<char,int> new_system;
    for (auto it: old_system)
    {
        for (auto st: std::get<1>(it))
        {
            auto ls = std::tolower(st, std::locale());
            new_system.insert(std::pair<char,int>(ls,std::get<0>(it)));
        }
    }
    return new_system;
}


}
