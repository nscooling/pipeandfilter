// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// IFilterTests.cpp
//
// ------------------------------------------------------------


#ifdef IFILTER_WITH_DOCTEST
#include "doctest.h"
#include "Pipe.h"
#include "Generator.h"
#include "Display.h"
#include "IFilter.h"

#include <string>
#include <iostream>
using namespace std;

class GDTests {
protected:
  GDTests() :g{p}, d{p}, gf(&g), df(&d) {}
  Pipe p{};
  GeneratorAdpt g{ p };
  DisplayAdpt   d{ p };
  I_Filter*    gf{ &g };
  I_Filter*    df{ &d };
};


TEST_CASE_FIXTURE(GDTests, "interface test") {
  string s1 = gf->execute();
  string s2 = df->execute();
  CHECK(s1 == s2);
}

#endif


