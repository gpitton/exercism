#include "food_chain.h"
#include <vector>


namespace food_chain
{


std::string verse(int recursion_level)
{
    std::vector<std::string> animal {"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
    std::vector<std::string> adjective {"It wriggled and jiggled and tickled inside her.", "How absurd to swallow a bird!", "Imagine that, to swallow a cat!", "What a hog, to swallow a dog!", "Just opened her throat and swallowed a goat!", "I don't know how she swallowed a cow!", "She's dead, of course!"};
    std::string closure {"I don\'t know why she swallowed the fly. Perhaps she\'ll die.\n"};
    std::string song {"I know an old lady who swallowed a "};
    
    song += animal[recursion_level-1] + ".\n";
    if (recursion_level>1)
        song += adjective[recursion_level-2] + "\n";
    if (recursion_level>7)
        return song;

    for (int i=recursion_level-1;i>0;--i)
    {
        song += "She swallowed the " + animal[i] + " to catch the " + animal[i-1];
        if (animal[i-1] == "spider")
            song += " that wriggled and jiggled and tickled inside her";
        song += ".\n";
    }
    song += closure;
    return song;
}


std::string verses(int v1, int v2)
{
    std::string required_verses;
    for (int i=v1; i<=v2; ++i)
    {
        required_verses += verse(i) + "\n";
    }
    return required_verses;
}


std::string sing ()
{
    return verses (1, 8);
}


}
