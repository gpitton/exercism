#include "robot_name.h"
#include <algorithm>


namespace robot_name
{

robot::robot()
:
generator(rd())
{
    reset();
}


std::string robot::name() const
{
    return robot_name;
}


void robot::reset()
{
    do {
        robot_name.clear();
        for (int i=0;i<2;++i)
            robot_name.push_back('A' + (rand_letter() + 'A')%26);
        for (int i=0;i<3;++i)
            robot_name += std::to_string(rand_number());
    } while (std::find(all_names.begin(), all_names.end(), robot_name) != all_names.end());
    all_names.push_back(robot_name);
}

}
