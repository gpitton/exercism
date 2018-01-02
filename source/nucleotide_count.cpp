#include "nucleotide_count.h"
#include <stdexcept>


namespace dna
{


counter::counter (std::string init_string)
{
    nucleotides_string = "ATCG";
    reference_string = init_string;
    classify_nucleotides ();
}


std::map<char,int> counter::nucleotide_counts () const
{
    return nucleotides;
}


int counter::count (const char chr) const
{
    if (nucleotides_string.find(chr) != std::string::npos)
        return nucleotides.find(chr)->second;
    else
        throw std::invalid_argument("invalid nucleotide identifier.");
}


void counter::classify_nucleotides ()
{
    for (auto it: nucleotides_string)
        nucleotides[it] = 0;
    for (auto it: reference_string)
        if (nucleotides_string.find(it) != std::string::npos)
            ++nucleotides[it];
        else
            throw std::invalid_argument("invalid nucleotide identifier.");
}


}
