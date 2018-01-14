#include "word_count.h"
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
        // remove leading apostrophe
        if (it[0] == '\'')
            it.erase(0,1);
        // remove trailing apostrophe
        int it_last = it.length()-1;
        if (it[it_last] == '\'')
            it.erase(it_last);
        if (it != "\0")
            ++counter[it];
    }
    return counter;
}


std::vector<std::string> split_string (const std::string& phrase)
{
    std::vector<std::string> words;
    std::string current_word;
    auto cleaned_phrase = filter_special_characters(phrase);
    auto clean_phrase = remove_multiple_spaces(cleaned_phrase);
    for (auto it = clean_phrase.begin(); it != clean_phrase.end(); ++it)
    {
        auto nt = it;
        ++nt;
        if (*it == ' ')
        {
            words.push_back(current_word);
            current_word.erase();
        }
        else if (nt == clean_phrase.end())
        {
            current_word.push_back(*it);
            words.push_back(current_word);
        }
        else
            current_word.push_back(*it);
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
    }
    return filtered_string;
}


std::string remove_multiple_spaces(const std::string& phrase)
{
    std::string few_spaces;
    char        pt;
    for (int i=0; i<phrase.length(); ++i)
    {
        char it = phrase[i];
        if (i>0)
            pt = phrase[i-1];
        if (!(it == ' ' && pt == ' '))
            few_spaces.push_back(it);
    }
    return few_spaces;
}


bool allowed_digit(const char& ct)
{
    return std::isalpha(ct,std::locale()) || std::isdigit(ct) || ct == '\'';
}

}
