// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Generator.h
//
// ------------------------------------------------------------
#ifndef GENERATOR_H_
#define GENERATOR_H_

class Pipe;
#include "Event.h"
class Generator
{
public:
  Generator(Pipe&);
  virtual ~Generator();
  Event::Alarm_t execute();
private:
  Pipe* thePipe;
};

#endif /* GENERATOR_H_ */
