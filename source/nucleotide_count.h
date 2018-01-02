#if !defined NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H
#include <map>
#include <string>


namespace dna
{

class counter
{
    public:
        counter (std::string);
        std::map<char,int> nucleotide_counts () const;
        int count (const char) const;

    private:
        std::string nucleotides_string;
        std::string reference_string;
        std::map<char,int> nucleotides;
        void classify_nucleotides ();
};

}

#endif
