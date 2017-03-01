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

static const std::array<const char*,4> msg{"noted", "careful", "danger","not applicable"};


Generator::Generator(Pipe& p):thePipe(&p)
{
}

Generator::~Generator()
{
  // TODO Auto-generated destructor stub
}

std::string Generator::execute()
{
  return execute(rand() % 20);
}

std::string Generator::execute(unsigned numOfMsgs)
{
  string str{};
  EventList evts {};
  //evts.reserve(numOfMsgs);

  for( ; numOfMsgs > 0 ; --numOfMsgs) {
    unsigned val = rand() % 3;
    evts.emplace_back(static_cast<Event::Alarm_t>(val), msg[val]);
  };

  for(auto i : evts) {
     str += i.typeAsString();
  }
  thePipe->push(std::move(evts));

  return str;
}
