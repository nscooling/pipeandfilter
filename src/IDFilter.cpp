// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// IDFilter.cpp
//
// ------------------------------------------------------------
#include "IDFilter.h"
#include "Event.h"
#include <memory>
#include "Pipe.h"

#include <algorithm>

IDFilter::IDFilter(Pipe& ip, Pipe& op):
source{&ip},
sink{&op}
{
  // TODO Auto-generated constructor stub

}

IDFilter::~IDFilter()
{
  // TODO Auto-generated destructor stub
}

std::string IDFilter::execute()
{
    auto evts = std::make_unique<EventList>();
    std::string str{};

    auto err = source->pull(evts);

    // Apply filter here

    auto it = std::remove_if(begin(*evts), end(*evts), [](Event& e){ return e.type() != Event::Alarm_t::WARNING;} );
    (*evts).erase(it, end(*evts));
    //

    if (err == Pipe::err_t::OK) {
      for(auto i : *evts) {
         str += i.typeAsString();
  #if DISPLAY
         std::cout << "Event received => " << i.typeAsString();
         std::cout << " : " << i.what() << std::endl;
  #endif
      }

    }

    sink->push(std::move(evts));
    return str;
}

#ifdef IDFilter_WITH_DOCTEST
#include "doctest.h"
#include "Pipe.h"
#include "Generator.h"
#include "Display.h"
#include <string>

class IDFilterTests {
protected:
  IDFilterTests():
    id_filter{inputp, outputp},
    g{inputp},
    d {outputp}
    {}
  Pipe inputp{};
  Pipe outputp{};
  IDFilter id_filter;
  Generator g;
  Display d;
};


TEST_CASE_FIXTURE(IDFilterTests, "initial test") {
  std::string s1 = g.execute();
  std::string s2 = id_filter.execute();
  std::string s3 = d.execute();
  CHECK(s1 != s2);
  CHECK(s2 == s3);
}

#endif
