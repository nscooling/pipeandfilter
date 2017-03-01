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
    e = std::move(elem);
    state = err_t::Empty;
    return err_t::OK;
  }
  else {
    return state;
  }
}


Pipe::err_t Pipe::push(pipe_elem& e)
{
  if(state != err_t::Full) {
    elem = std::move(e);
    state = err_t::Full;
    return err_t::OK;
  }
  else {
    return state;
  }
}

//Pipe::err_t Pipe::push(pipe_elem&& e)
//{
//  if(state != err_t::Full) {
//    elem = std::move(e);
//    state = err_t::Full;
//    return err_t::OK;
//  }
//  else {
//    return state;
//  }
//}


#ifdef PIPE_WITH_DOCTEST
#include "doctest.h"
#include <algorithm>
#include <memory>

class PipeTests {
protected:
  Pipe p{};
//  EventList e{
//    Event{Event::Alarm_t::NA, ""},
//    Event{Event::Alarm_t::ADVISORY, "watch out"},
//    Event{Event::Alarm_t::CAUTION, "careful now"},
//    Event{Event::Alarm_t::WARNING, "oh bugger"}
//  };
  pipe_elem e{};
  PipeTests() {
    e = std::make_unique<EventList>();
    e->reserve(4);
    e->emplace_back();
    e->emplace_back(Event::Alarm_t::ADVISORY, "watch out");
    e->emplace_back(Event::Alarm_t::CAUTION, "careful now");
    e->emplace_back(Event::Alarm_t::WARNING, "oh bugger");
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
  CHECK(e->size() == 4);

  auto local = std::make_unique<EventList>();
  CHECK(local->size() == 0);

  p.push(e);
  CHECK(e == nullptr);

  p.pull(local);
  CHECK(local->size() == 4);

  CHECK((*local)[0].type() == Event::Alarm_t::NA);
  CHECK((*local)[1].type() == Event::Alarm_t::ADVISORY);
  CHECK((*local)[2].type() == Event::Alarm_t::CAUTION);
  CHECK((*local)[3].type() == Event::Alarm_t::WARNING);
}

//TEST_CASE_FIXTURE(PipeTests, "move-push then pull") {
//  CHECK(e.size() == 4);
//
//  EventList dlocal{};
//  p.push(std::move(e));
//  CHECK(e.size() == 0);
//
//  p.pull(dlocal);
//  CHECK(dlocal.size() == 4);
//
//  CHECK(dlocal[0].type() == Event::Alarm_t::NA);
//  //  CHECK(e == local);
//  //  CHECK(true = std::equal(begin(e), end(e), begin(local)));
//}

#endif
