#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>


namespace anagram
{

  class anagram
  {
      public:
          anagram (std::string);
          std::vector<std::string> matches (const std::vector<std::string>&);
      private:
          std::string original_name;
          bool is_anagram(const std::string&) const;
  };

  
}

#endif
