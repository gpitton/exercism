#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H
#include <string>


class phone_number
{
    public:
        phone_number (std::string);
        std::string number () const;
        std::string area_code () const;
        operator std::string () const;
    private:
        std::string my_phone_number;
        void parse_string (std::string&, std::string&);
        void check_prefix (std::string&);
};

#endif
