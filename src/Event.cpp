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

static const std::array<const char*,4> msg{"ADVISORY", "CAUTION", "WARNING","NA"};

Event::Event(Alarm_t the_alarm): theAlarm{the_alarm}
{
//  st << "alarm ctor\n";
}

Event::~Event()
{
// std::cout << "alarm dtor\n";
}

Event::Alarm_t Event::type() const
{
  return theAlarm;
}

const char* Event::typeAsString() const
{
  return msg.at(static_cast<int>(theAlarm));
}

Event::operator const char*() const
{
  return msg.at(static_cast<int>(theAlarm));
}

#ifdef EVENT_WITH_DOCTEST
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

class EventTests {
protected:
  Event e{};
  Event a{Event::Alarm_t::ADVISORY};
  Event c{Event::Alarm_t::CAUTION};
  Event w{Event::Alarm_t::WARNING};
};

TEST_CASE_FIXTURE(EventTests, "type test") {
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

#endif
