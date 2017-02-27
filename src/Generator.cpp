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

Generator::Generator(Pipe& p):thePipe(&p)
{
}

Generator::~Generator()
{
  // TODO Auto-generated destructor stub
}


Event::Alarm_t Generator::execute() {
  Event e{};
  auto err = thePipe->push(e);
  return e.type();
}
