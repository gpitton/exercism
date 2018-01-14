#if !defined(BOB_H)
#define BOB_H
#include <string>


namespace bob
{
bool is_all_caps(const std::string&);
bool has_no_content(const std::string&);
char get_last_non_space(const std::string&);
std::string hey(const std::string&);
}

#endif
