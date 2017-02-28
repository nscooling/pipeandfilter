// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Pipe.cpp
//
// ------------------------------------------------------------
#include "Pipe.h"

Pipe::Pipe()
{
  // TODO Auto-generated constructor stub

}

Pipe::~Pipe()
{
  // TODO Auto-generated destructor stub
}

Pipe::err_t Pipe::pull(pipe_elem& e)
{
  if(state != err_t::Empty) {
    e = elem;
    state = err_t::Empty;
    return err_t::OK;
  }
  else {
    return state;
  }
}


Pipe::err_t Pipe::push(const pipe_elem& e)
{
  if(state != err_t::Full) {
    elem = e;
    state = err_t::Full;
    return err_t::OK;
  }
  else {
    return state;
  }
}


#ifdef PIPE_WITH_DOCTEST
#include "doctest.h"

class PipeTests {
protected:
  Pipe p{};
  EventList e{
    Event{},
    Event{Event::Alarm_t::ADVISORY},
    Event{Event::Alarm_t::CAUTION},
    Event{Event::Alarm_t::WARNING}
  };
};

TEST_CASE_FIXTURE(PipeTests, "empty pull") {
  CHECK(Pipe::err_t::Empty == p.pull(e));
}

TEST_CASE_FIXTURE(PipeTests, "empty push") {
  CHECK(Pipe::err_t::OK == p.push(e));
}

TEST_CASE_FIXTURE(PipeTests, "full push") {
  p.push(e);
  CHECK(Pipe::err_t::Full == p.push(e));
}

TEST_CASE_FIXTURE(PipeTests, "push then pull") {
  EventList local{};
  p.push(e);
  p.pull(local);
  CHECK(e == local);
}

#endif
