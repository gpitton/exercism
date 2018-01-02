#if !defined(GIGASECOND_H)
#define GIGASECOND_H
#define EXERCISM_RUN_ALL_TESTS
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

namespace gigasecond
{

  ptime advance(ptime);

  ptime advance(ptime start_time)
  {
    ptime Gs = start_time + seconds(1e9);
    return Gs;
  }

}

#endif
