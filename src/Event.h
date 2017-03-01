// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Event.h
//
// ------------------------------------------------------------
#ifndef SRC_EVENT_H_
#define SRC_EVENT_H_
#include <vector>
#include <iostream>

class Event
{
public:
  enum class Alarm_t { ADVISORY, CAUTION, WARNING, NA };
  Event() = default;
  Event(Alarm_t the_alarm);
  Event(Alarm_t the_alarm,  const char*);
  Event(const Event&);
  Event& operator=(Event);
  ~Event();

  Alarm_t type() const;
  const char* typeAsString() const;
  const char* what() const;


private:
  Alarm_t theAlarm { Alarm_t::NA };
  char* str{ nullptr };

  friend void swap(Event& lhs, Event& rhs);
  friend bool operator==(const Event& lhs, const Event& rhs);
};

void swap(Event& lhs, Event& rhs);
bool operator==(const Event& lhs, const Event& rhs);

using EventList = std::vector<Event>;

#endif /* SRC_EVENT_H_ */
