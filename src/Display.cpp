// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Display.cpp
//
// ------------------------------------------------------------
#include "Display.h"
#include <iostream>
#include "Pipe.h"
#include <string>

Display::Display(Pipe& p):thePipe(&p)
{
}

Display::~Display()
{
  // TODO Auto-generated destructor stub
}

std::string Display::execute() {
  auto evts = std::make_unique<EventList>();
  std::string str{};

  auto err = thePipe->pull(evts);
  if (err == Pipe::err_t::OK) {
    for(auto i : *evts) {
       str += i.typeAsString();
#if DISPLAY
       std::cout << "Event received => " << i.typeAsString();
       std::cout << " : " << i.what() << std::endl;
#endif
    }

  }
  return str;
}
