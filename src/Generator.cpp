// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Generator.cpp
//
// ------------------------------------------------------------
#include "Generator.h"
#include "Pipe.h"
#include "Event.h"
#include <cstdlib>
#include <array>
using namespace std;

Generator::Generator(Pipe& p):thePipe(&p)
{
}

Generator::~Generator()
{
  // TODO Auto-generated destructor stub
}


std::string Generator::execute()
{
  string str{};

  EventList evts {
    Event{},
    Event{Event::Alarm_t::ADVISORY},
    Event{Event::Alarm_t::CAUTION},
    Event{Event::Alarm_t::WARNING}
  };

  auto err = thePipe->push(evts);
  if(err == Pipe::err_t::OK) {
    for(auto i : evts) {
       str += i.typeAsString();
    }
  }
  return str;
}
