// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Event.cpp
//
// ------------------------------------------------------------
#include "Event.h"
#include <iostream>
#include <array>
#include <cstring>

static const std::array<const char*,4> msg{"ADVISORY", "CAUTION", "WARNING","NA"};



Event::Event(Alarm_t the_alarm): theAlarm{the_alarm}
{
#if COUT
  std::cout << "Event::Event(Alarm_t the_alarm)\n";
#endif
}

Event::Event(Alarm_t the_alarm, const char *name): theAlarm{the_alarm}
{
#if COUT
  std::cout << "Event::Event(Alarm_t the_alarm, const char *name)\n";
#endif
  if(name != nullptr) {
    str = new char[strlen(name)+1];
    strcpy(str,name);
  }
  else {
    str = nullptr;
  }
}

Event::Event(const Event& cp): Event{cp.theAlarm, cp.str}
{
#if COUT
  std::cout << "Event::Event(const Event& cp)\n";
#endif
}

Event::Event(Event&& rval) noexcept :
    Event{}
{
#if COUT
  std::cout << "Event::Event(Event&& cp)\n";
#endif
  swap(*this,rval);
}

Event& Event::operator=(Event rhs)
{
#if COUT
  std::cout << "Event::opertor=(Event rhs)\n";
#endif
  swap(*this, rhs);
  return *this;
}

Event::~Event()
{
#if COUT
  std::cout << "Event::~Event()\n";
#endif
  delete [] str;
}

Event::Alarm_t Event::type() const
{
  return theAlarm;
}

const char* Event::typeAsString() const
{
  return msg.at(static_cast<int>(theAlarm));
}

const char* Event::what () const
{
  return str;
}

void swap(Event& lhs, Event& rhs)
{
  using std::swap;
 swap(lhs.theAlarm, rhs.theAlarm);
 swap(lhs.str, rhs.str);
}

bool operator==(const Event& lhs, const Event& rhs)
{
  return ((lhs.theAlarm == rhs.theAlarm) && (lhs.str == rhs.str));
}

#ifdef EVENT_WITH_DOCTEST
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

class EventTests {
protected:
  Event e{Event::Alarm_t::NA, "N-A"};
  Event a{Event::Alarm_t::ADVISORY, "Advisory"};
  Event c{Event::Alarm_t::CAUTION, "Caution"};
  Event w{Event::Alarm_t::WARNING, "Warning"};
};

TEST_CASE_FIXTURE(EventTests, "type test") {
  Event empty{};
  CHECK(empty.type() == Event::Alarm_t::NA);

  CHECK(e.type() == Event::Alarm_t::NA);
  CHECK(a.type() == Event::Alarm_t::ADVISORY);
  CHECK(c.type() == Event::Alarm_t::CAUTION);
  CHECK(w.type() == Event::Alarm_t::WARNING);
}

TEST_CASE_FIXTURE(EventTests, "string test") {
  CHECK( e.typeAsString() == "NA");
  CHECK( a.typeAsString() == "ADVISORY");
  CHECK( c.typeAsString() == "CAUTION");
  CHECK( w.typeAsString() == "WARNING");
}

TEST_CASE_FIXTURE(EventTests, "resource string test") {

  Event empty{};
  CHECK(empty.what() == nullptr);
  Event emptyStr{Event::Alarm_t::NA};
  CHECK(emptyStr.what() == nullptr);

  CHECK( std::string{e.what()} == std::string{"N-A"});
  CHECK( std::string{a.what()} == std::string{"Advisory"});
  CHECK( std::string{c.what()} == std::string{"Caution"});
  CHECK( std::string{w.what()} == std::string{"Warning"});
}

TEST_CASE_FIXTURE(EventTests, "copy-ctor test") {
  {
    Event copy(a);
    CHECK( std::string{copy.what()} == std::string{"Advisory"});
  }
  CHECK( std::string{a.what()} == std::string{"Advisory"});
}

TEST_CASE_FIXTURE(EventTests, "op= test") {
  {
    Event copy(Event::Alarm_t::CAUTION, "Caution");
    CHECK( std::string{copy.what()} == std::string{"Caution"});
    copy = a;
    CHECK( std::string{copy.what()} == std::string{"Advisory"});
  }
  CHECK( std::string{a.what()} == std::string{"Advisory"});
}

TEST_CASE_FIXTURE(EventTests, "move test") {
  Event copy(Event::Alarm_t::CAUTION, "Move Caution");
  CHECK( copy.type() == Event::Alarm_t::CAUTION );
  CHECK(a.type() == Event::Alarm_t::ADVISORY);

  a = std::move(copy);

  CHECK( copy.type() == Event::Alarm_t::NA );
  CHECK( a.type() == Event::Alarm_t::CAUTION );
}

#endif
