#include "phone_number.h"
#include <cctype>


phone_number::phone_number (std::string digit)
{
    parse_string (digit, my_phone_number);
}


std::string phone_number::number () const
{
    return my_phone_number;
}


std::string phone_number::area_code () const
{
    return my_phone_number.substr (0,3);
}


phone_number::operator std::string () const
{
    return '(' + area_code() + ") " + my_phone_number.substr(3,3) + '-' + my_phone_number.substr(6);
}


void phone_number::parse_string (std::string& src, std::string& dst)
{
    for (auto it: src)
    {
        if (std::isdigit(it))
            dst += it;
    }
    check_prefix (dst);
    if (dst.length() != 10)
        dst = "0000000000";
}


void phone_number::check_prefix (std::string& src)
{
    if (src[0] == '1' && src[1] == '1')
        src.erase(0,1);
}
