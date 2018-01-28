#if !defined(TRIANGLE_H)
#define TRIANGLE_H
#include <cmath>
#include <stdexcept>


namespace triangle
{

enum triangle_type {equilateral, isosceles, scalene};

// checks triangle inequality
template<typename T>
bool check_triangle(const T a, const T b, const T c)
{
    if ((a + b) <= c)
        return false;
    if ((b + c) <= a)
        return false;
    if ((c + a) <= b)
        return false;
    return true;
}

template<typename T>
triangle_type kind(const T a, const T b, const T c)
{
    if (a <=0 || b <= 0 || c <= 0)
        throw std::domain_error("One of the sides is a negative number");
    if (!check_triangle<T>(a,b,c))
        throw std::domain_error("Sides do not fulfil the triangle inequality");
    if (a == b && b == c)
        return triangle_type::equilateral;
    else if (a == b || a == c || b == c)
        return triangle_type::isosceles;
    else return triangle_type::scalene;
}

}

#endif
