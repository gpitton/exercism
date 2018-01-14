#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <string>
#include <vector>


namespace grade_school
{

class school
{
public:
    std::map<int,std::vector<std::string>> roster();
    void add(const std::string&,int);
    std::vector<std::string> grade(int);
private:
    std::map<int,std::vector<std::string>> sort_roster();
    std::map<int,std::vector<std::string>> school_roster {};
};

}
#endif
