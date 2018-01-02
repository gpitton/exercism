#include "word_count.h"
#include <iostream>
#include <locale>
#include <cctype>


namespace word_count
{

  std::map<std::string,int> words (const std::string& phrase)
  {
    std::map<std::string,int> counter;
    auto words = word_count::split_string(phrase);
    for (auto it: words)
    {
      ++counter[it];
      std::cout << it << counter[it] << std::endl;
    }
    return counter;
  }


  std::vector<std::string> split_string (const std::string& phrase)
  {
    std::vector<std::string> words;
    std::string current_word;
    auto cleaned_phrase = filter_special_characters(phrase);
    auto clean_phrase = remove_multiple_spaces(cleaned_phrase);
    for (auto it: clean_phrase)
    {
      if (it == ' ')
      {
        words.push_back(current_word);
        current_word.erase();
      }
      else
      {
        current_word.push_back(it);
      }
    }
    return words;
  }

  std::string filter_special_characters (const std::string& phrase)
  {
    std::string filtered_string;
    for (auto it = phrase.begin(); it != phrase.end(); ++it)
    {
      if (allowed_digit(*it))
        filtered_string.push_back(std::tolower(*it));
      else
        filtered_string.push_back(' ');
      auto nt = it, pt = it;
      ++nt;
      --pt;
      if (nt != phrase.end() && pt != phrase.begin())
      if (*it == '\'' && std::isalpha(*pt,std::locale()) && std::isalpha(*nt,std::locale()))
        filtered_string.push_back(*it);
    }
    return filtered_string;
  }


  std::string remove_multiple_spaces(std::string& phrase)
  {
    std::string few_spaces;
    for (auto it = phrase.begin(); it != phrase.end(); ++it)
    {
      auto pt = it;
      --pt;
      if (pt != phrase.begin())
      if (*it == ' ' && *pt == ' ')
          break;
      else
          few_spaces.push_back(*it);
    }
    return few_spaces;
  }


  bool allowed_digit(const char& ct)
  {
    return std::isalpha(ct,std::locale()) || std::isdigit(ct);
  }

}
