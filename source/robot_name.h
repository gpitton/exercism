#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <functional>
#include <random>
#include <string>
#include <vector>


namespace robot_name
{

class robot
{
    public:
    robot();
    std::string name() const;
    void reset();
    private:
    std::random_device rd;
    std::default_random_engine generator;
    //std::mt19937 generator;  // Mersenne Twister
    std::function<int(void)> rand_letter = std::bind (std::uniform_int_distribution<int>(0,25),generator);
    std::function<int(void)> rand_number = std::bind (std::uniform_int_distribution<int>(0,9),generator);
    std::string robot_name;
    std::vector<std::string> all_names;
};

}

#endif
