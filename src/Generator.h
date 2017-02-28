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

// TODO do forward reference here
#include <string>

class Generator
{
public:
  Generator(Pipe&);
  virtual ~Generator();
  std::string execute(unsigned = 1U);
private:
  Pipe* thePipe;
};

#endif /* GENERATOR_H_ */
