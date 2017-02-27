// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// generatorDisplayTests.cpp
//
// ------------------------------------------------------------

#ifdef GDT_WITH_DOCTEST
#include "doctest.h"
#include "Pipe.h"
#include "Generator.h"

class GDTests {
protected:
  GDTests():g(p){}
  Pipe p{};
  Generator g;
};

TEST_CASE_FIXTURE(GDTests, "initial test") {
  CHECK(Event::Alarm_t::NA == g.execute());
}


#endif
