#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H
#include <cctype> // required for std::toupper
#include <map>
#include <string>
#include <vector>

namespace scrabble_score {

unsigned int score(const std::string& word)
{
    std::map<char, unsigned int> letter_value {{'A',1},{'D',2},{'B',3},{'F',4},{'K',5},{'J',8},{'Q',10}};
    std::vector<std::string> equivalences {"AEIOULNRST","DG","BCMP","FHVWY","K","JX","QZ"};

   if (word == "")
       return 0;

   unsigned int value = 0;
   for (auto letter: word)
   {
       for (auto eq: equivalences)
           if (eq.find(std::toupper(letter)) != std::string::npos)
               value += letter_value[eq[0]];
   }

   return value;
}

}
#endif
