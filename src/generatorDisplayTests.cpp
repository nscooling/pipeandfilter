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
#include "Display.h"

#include <string>
#include <iostream>
using namespace std;

class GDTests {
protected:
  GDTests():g{p}, d{p}{}
  Pipe p{};
  Generator g;
  Display d;
};

TEST_CASE_FIXTURE(GDTests, "initial test") {
  string s1 = g.execute();
  string s2 = d.execute();
  CHECK(s1 == s2);
}


#endif
