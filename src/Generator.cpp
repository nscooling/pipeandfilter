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

Generator::Generator(Pipe& p):thePipe(&p)
{
}

Generator::~Generator()
{
  // TODO Auto-generated destructor stub
}


std::string Generator::execute() {
  std::array<Event, 4> evts {
    Event{},
    Event{Event::Alarm_t::ADVISORY},
    Event{Event::Alarm_t::CAUTION},
    Event{Event::Alarm_t::WARNING}
  };

  int choice = std::rand() % 4;
  auto err = thePipe->push(evts[choice]);
  return evts[choice].typeAsString();
}
