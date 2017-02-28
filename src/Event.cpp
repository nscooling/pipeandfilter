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
  std::cout << "Event::Event(Alarm_t the_alarm)\n";
}

Event::Event(Alarm_t the_alarm, const char *name): theAlarm{the_alarm}
{
  std::cout << "Event::Event(Alarm_t the_alarm, const char *name)\n";
  if(name != nullptr) {
    str = new char[strlen(name)+1];
    strcpy(str,name);
  }
}

Event::Event(const Event& cp): Event{cp.theAlarm, cp.str}
{
  std::cout << "Event::Event(const Event& cp)\n";
}

Event& Event::operator=(Event rhs)
{
  std::cout << "Event::opertor=(const Event rhs)\n";
  swap(*this, rhs);
  return *this;
}

Event::~Event()
{
  std::cout << "Event::~Event()\n";
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
  std::swap(lhs.theAlarm, rhs.theAlarm);
  std::swap(lhs.str, rhs.str);
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


#endif
