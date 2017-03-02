// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// RunnableFilter.cpp
//
// ------------------------------------------------------------
#include "RunnableFilter.h"
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

RunnableFilter::RunnableFilter(I_Filter& f):theFilter{&f}
{
  // TODO Auto-generated constructor stub

}

RunnableFilter::~RunnableFilter()
{
  // TODO Auto-generated destructor stub
}

void RunnableFilter::run()
{
  std::string str{};
  do {
    str = theFilter->execute();
    if( str == std::string{}) {
      this_thread::sleep_for(chrono::milliseconds{200});
    }
  }while(str != std::string("NA"));
}


#ifdef RUNFILTER_WITH_DOCTEST
#include "doctest.h"
#include "Pipe.h"
#include "Generator.h"
#include "Display.h"
#include "IDFilter.h"

class RunnableFiltersTests {
protected:
  RunnableFiltersTests()
    {}
  Pipe g2f{};
  Pipe f2d{};
  IDFilter id_filter { g2f, f2d };
  GeneratorAdpt ga{ g2f };
  DisplayAdpt   da{ f2d };
  I_Filter*     gf{ &ga };
  I_Filter*     wf{ &id_filter };
  I_Filter*     df{ &da };
};


TEST_CASE_FIXTURE(RunnableFiltersTests, "initial test") {
  RunnableFilter rf1{*wf};
  RunnableFilter rf2{*df};
  std::thread t1 { &IRunnable::run, &rf1 };
  std::thread t2 { &IRunnable::run, &rf2 };

  // populate pipe
  for(int i = 0; i < 2; ++i) {
    gf->execute();
    this_thread::sleep_for(chrono::milliseconds{1000});
  }

  // Add terminating thread condition
  IDFilter* filter = dynamic_cast<IDFilter*>(wf);
  if(filter != nullptr) {
      filter->setFilterType(Event::Alarm_t::NA);
  }
  auto events = {
      Event{Event::Alarm_t::NA, ""},
  };
  g2f.push(std::make_unique<EventList>(events));


  t1.join();
  t2.join();

  // for test to report
  CHECK(1==1);
}



#endif
