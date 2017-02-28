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

#endif /* SRC_DISPLAY_H_ */
