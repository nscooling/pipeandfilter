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
#include <memory>
#include <mutex>
#include <condition_variable>

#include "Buffer.h"
using pipe_elem = std::unique_ptr<EventList>;

class Pipe
{
public:

  enum class err_t { OK, Empty, Full };
  Pipe();
  virtual ~Pipe();
  err_t pull(pipe_elem&);
//  err_t push(const pipe_elem&);
  err_t push(pipe_elem&&);
private:
  err_t state { err_t::Empty};
  Buffer<pipe_elem,2> elem{};
  std::mutex mtx;
  std::condition_variable hasData;
  std::condition_variable hasSpace;
};

#endif /* SRC_PIPE_H_ */
