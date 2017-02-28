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
  Event e{};
  auto err = thePipe->pull(e);
  if (err == Pipe::err_t::OK) {
    std::cout << "Event received => " << e << std::endl;
  }
  return e.typeAsString();
}
