// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// main.cpp
//
// ------------------------------------------------------------
#include "Event.h"
#include <iostream>


int main()
{
  Event e{};
  Event f{Event::Alarm_t::ADVISORY};
  if(e.type() != Event::Alarm_t::NA) {
    std::cerr << "Big bug\n";
  }
  if(f.type() != Event::Alarm_t::ADVISORY) {
    std::cerr << "Big bug\n";
  }
  std::cout << e.typeAsString() << std::endl;
  std::cout << f.typeAsString() << std::endl;
  std::cout << e << std::endl;
  std::cout << f << std::endl;
}
