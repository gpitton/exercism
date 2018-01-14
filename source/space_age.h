#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H
#include <map>
#include <string>


namespace space_age
{

class space_age
{
public:
    space_age (long int);
    long int seconds () const;
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;
private:
    long int my_age_seconds;
    const double seconds_to_year {1./31557600.};
    const std::map<std::string,double> planet_to_earth {{"mercury",0.2408467},{"venus",0.61519726},{"mars",1.8808158},{"jupiter",11.862615},{"saturn",29.447498},{"uranus",84.016846},{"neptune",164.79132}};
};

}

#endif
