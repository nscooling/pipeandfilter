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

class Event
{
public:
  enum class Alarm_t { ADVISORY, CAUTION, WARNING, NA };

  Event() = default;
  Event(Alarm_t the_alarm);
  Event(const Event&);
  Event& operator=(const Event&);
  ~Event();

  Alarm_t type() const;
  const char* typeAsString() const;
  operator const char*() const;
private:
  Alarm_t theAlarm { Alarm_t::NA };
};

using EventList = std::vector<Event>;

#endif /* SRC_EVENT_H_ */
