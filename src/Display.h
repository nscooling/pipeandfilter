// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Display.h
//
// ------------------------------------------------------------
#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_

#include "IFilter.h"

class Pipe;

// TODO do forward reference here
#include <string>

class Display
{
public:
  Display(Pipe&);
  virtual ~Display();
  std::string execute();
private:
  Pipe* thePipe;
};

class DisplayAdpt : public I_Filter
{
public:
  DisplayAdpt(Pipe& p): d(p){}
protected:
  std::string execute() override { return d.execute(); }
private:
  Display d;
};

#endif /* SRC_DISPLAY_H_ */
