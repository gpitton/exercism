#if !defined(HAMMING_H)
#define HAMMING_H
#include <stdexcept>
#include <string>


namespace hamming
{
  int compute(std::string str1, std::string str2)
  {
      if (str1.length() != str2.length())
          throw std::domain_error("input strings must have equal length");
      int distance = 0;
      auto it2 = str2.begin();
      for (auto it1 = str1.begin(); it1 != str1.end(); ++it1, ++it2)
      {
          if (*it1 != *it2)
              ++distance;
      }
      return distance;
  }
}


#endif
