#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <string>
#include <vector>
#include <map>


namespace word_count
{

  std::map<std::string,int> words (const std::string&);
  std::vector<std::string> split_string (const std::string&);
  std::string filter_special_characters (const std::string&);
  std::string remove_multiple_spaces (std::string&);
  bool allowed_digit (const char&);
}

#endif
