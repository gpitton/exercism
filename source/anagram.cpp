#include "anagram.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>


namespace anagram
{


  anagram::anagram(std::string name)
    {
      original_name = name;
    }


  std::vector<std::string> anagram::matches (const std::vector<std::string>& names)
  {
    std::vector<std::string> are_anagrams;
    //for (auto it = names.begin(); it != names.end(); ++it)
    for (auto it : names)
    {
      if (anagram::is_anagram(it))
          are_anagrams.push_back(it);
    }
    return are_anagrams;
  }


  bool anagram::is_anagram (const std::string& src) const
  {
    std::string copied_src = boost::algorithm::to_lower_copy(src),
                copied_name = boost::algorithm::to_lower_copy(original_name);
    if (copied_src == copied_name)
        return false;

    std::sort(copied_src.begin(), copied_src.end());
    std::sort(copied_name.begin(), copied_name.end());
    if (copied_name == copied_src)
        return true;
    else
        return false;
  }

  
}
