#if !defined(LEAP_H)
#define LEAP_H
#define EXERCISM_RUN_ALL_TESTS

namespace leap
{
  bool is_leap_year(int);

  bool is_leap_year(int year)
  {
      return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
  }
  /*
  {
    bool is_leap = (year % 4 == 0) ? true : false;
    if (year % 100)
        is_leap = false;
    if (year % 400)
        is_leap = true;
    return is_leap;
  }
  */
}

#endif
