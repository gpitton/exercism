#include "bob.h"
#include <string>
#include <cctype>
#include <locale>


namespace bob
{

bool is_all_caps(const std::string& str)
{
    std::locale loc;
    int count_uppercase = 0,
        count_letters = 0;
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (std::isalpha(*it,loc))
        {
            ++count_letters;
            if (isupper(*it))
                ++count_uppercase;
        }
    }
    if (count_letters>0 && count_uppercase == count_letters)
        return true;
    else
        return false;
}


bool has_no_content(const std::string& str)
{
    int count_spaces = 0;
    if (str.length() == 0)
        return true;
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == ' ')
            ++count_spaces;
    }
    if (count_spaces == str.length())
        return true;
    else
        return false;
}


char get_last_non_space(const std::string& str)
{
    for (auto it = str.rbegin(); it != str.rend(); ++it)
    {
        if (*it != ' ')
            return *it;
    }
    return ' ';
}


std::string hey(const std::string& str1)
{
    //auto last_char = str1.back();
    auto last_char = get_last_non_space(str1);
    if (bob::is_all_caps(str1))
        return "Whoa, chill out!";
    if (last_char == '?')
        return "Sure.";
    if (has_no_content(str1))
        return "Fine. Be that way!";
    return "Whatever.";
}


}
