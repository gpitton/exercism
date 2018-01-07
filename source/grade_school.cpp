#include "grade_school.h"
#include <algorithm>


namespace grade_school
{

std::map<int,std::vector<std::string>> school::roster()
{
    auto sorted_roster = sort_roster();
    return sorted_roster;
}


void school::add(const std::string name,int n_grade)
{
    school_roster[n_grade].push_back(name);
}


std::vector<std::string> school::grade(int n_grade)
{
    if (school_roster.count(n_grade) > 0)
    {
        auto names = school_roster[n_grade];
        std::sort(names.begin(),names.end());
        return names;
    }
    else
        return std::vector<std::string>();
}


std::map<int,std::vector<std::string>> school::sort_roster()
{
    std::map<int,std::vector<std::string>> ordered_roster;
    for (const auto& [grade,names]: school_roster)
    {
        auto n_names = school_roster[grade];
        std::sort(n_names.begin(),n_names.end());
        ordered_roster[grade] = n_names;
    }
    return ordered_roster;
}

}
