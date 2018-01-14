#include "space_age.h"


namespace space_age
{

space_age::space_age(long int given_age)
    :
    my_age_seconds {given_age}
{}


long int space_age::seconds() const
{
    return my_age_seconds;
}


double space_age::on_earth() const
{
    return my_age_seconds*seconds_to_year;
}


double space_age::on_mercury() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("mercury");
}


double space_age::on_venus() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("venus");
}


double space_age::on_mars() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("mars");
}


double space_age::on_jupiter() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("jupiter");
}


double space_age::on_saturn() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("saturn");
}


double space_age::on_uranus() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("uranus");
}


double space_age::on_neptune() const
{
    return my_age_seconds*seconds_to_year/planet_to_earth.at("neptune");
}

}
