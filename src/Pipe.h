// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Pipe.h
//
// ------------------------------------------------------------
#ifndef SRC_PIPE_H_
#define SRC_PIPE_H_

#include "Event.h"

//using pipe_elem = Event;
using pipe_elem = EventList;

class Pipe
{
public:
  enum class err_t { OK, Empty, Full };
  Pipe();
  virtual ~Pipe();
  err_t pull(pipe_elem&);
  err_t push(const pipe_elem&);
  err_t push(pipe_elem&&);
private:
  err_t state { err_t::Empty};
  pipe_elem elem{};
};

#endif /* SRC_PIPE_H_ */
