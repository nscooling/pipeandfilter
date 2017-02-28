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

#include "IFilter.h"

class Pipe;

// TODO do forward reference here
//#include <string>

class Generator
{
public:
  Generator(Pipe&);
  virtual ~Generator();
  std::string execute();
private:
  std::string execute(unsigned);
  Pipe* thePipe;
};

class GeneratorAdpt : public I_Filter
{
public:
  GeneratorAdpt(Pipe& p): g(p){}
protected:
  std::string execute() override { return g.execute(); }
private:
  Generator g;
};

#endif /* GENERATOR_H_ */
