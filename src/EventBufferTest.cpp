// ----------------------------------------------------------------------------------
// EventBufferTest.cpp
//
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any
// warranty
// of the item whatsoever, whether express, implied, or statutory, including,
// but
// not limited to, any warranty of merchantability or fitness for a particular
// purpose or any warranty that the contents of the item will be error-free.
// In no respect shall Feabhas incur any liability for any damages, including,
// but
// limited to, direct, indirect, special, or consequential damages arising out
// of,
// resulting from, or any way connected to the use of the item, whether or not
// based upon warranty, contract, tort, or otherwise; whether or not injury was
// sustained by persons or property or otherwise; and whether or not loss was
// sustained from, or arose out of, the results of, the item, or any services
// that
// may be provided by Feabhas.
// ----------------------------------------------------------------------------------




//###################################################################################
#ifdef EVENTBUFFER_WITH_DOCTEST

#include "Event.h"
#include "Buffer.h"

#include <vector>

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("[event buffer] testing buffer") {
  using testType = Event;
  constexpr unsigned sz = 8;
  using theBuffer = Buffer<testType, sz>;
  theBuffer buffer;
  theBuffer::Error err;

  std::vector<Event> evts {};
  evts.reserve(4);
  evts.emplace_back(Event::Alarm_t::NA, "N-A");
  evts.emplace_back(Event::Alarm_t::ADVISORY, "Advisory");
  evts.emplace_back(Event::Alarm_t::CAUTION, "Caution");
  evts.emplace_back(Event::Alarm_t::WARNING, "Warning");


  // if a REQUIRE() fails - execution of the test stops.
  REQUIRE(buffer.isEmpty() == true); 
  REQUIRE(buffer.size() == size_t(0));

  SUBCASE("added element") {
    err = buffer.add(evts[0]);
    //  If a CHECK() fails - the test is marked as failed but the execution continues
    CHECK(buffer.isEmpty() == false);
    CHECK(buffer.size() == size_t(1));
    CHECK(err == theBuffer::OK);
  }

  SUBCASE("added element") {
    err = buffer.add(Event{Event::Alarm_t::NA, "N-A"});
    //  If a CHECK() fails - the test is marked as failed but the execution continues
    CHECK(buffer.isEmpty() == false);
    CHECK(buffer.size() == size_t(1));
    CHECK(err == theBuffer::OK);
  }

  SUBCASE("test_initial_get") {
    testType data{};
    err = buffer.get(data);

    CHECK(err == theBuffer::EMPTY);
  }

  SUBCASE("test_initial_putget") {
    err = buffer.add(Event{Event::Alarm_t::ADVISORY, "Advisory"});
    testType data{};
    err = buffer.get(data);

    CHECK(err == theBuffer::OK);
    CHECK(true == buffer.isEmpty());
    CHECK(buffer.size() == size_t(0));
    CHECK(Event::Alarm_t::ADVISORY == data.type());
  }

  SUBCASE("test_initial_buffer_full") {
    static const std::array<const char*,4> msg{"noted", "careful", "danger","not applicable"};
    for (unsigned i = 0; i < sz; ++i) {
      err = buffer.add(Event{static_cast<Event::Alarm_t>(i%4), msg[i%4]});
      CHECK(err == theBuffer::OK);
    }
    CHECK(buffer.size() == size_t(sz));
    err = buffer.add(Event{Event::Alarm_t::ADVISORY, "Advisory"});

    CHECK(err == theBuffer::FULL);
  }

  SUBCASE("test_initial_buffer_full_to_empty") {
    static const std::array<const char*,4> msg{"noted", "careful", "danger","not applicable"};
    constexpr unsigned halfSz = sz / 2;
    testType data{};

    for (unsigned i = 0; i < sz; ++i) {
      err = buffer.add(Event{static_cast<Event::Alarm_t>(i%4), msg[i%4]});
      CHECK(err == theBuffer::OK);
    }
    for (unsigned i = 0; i < halfSz; ++i) {
      err = buffer.get(data);
      CHECK(err == theBuffer::OK);
      CHECK(static_cast<Event::Alarm_t>(i%4) == data.type());
    }
    for (unsigned i = 0; i < halfSz; ++i) {
      err = buffer.add(Event{static_cast<Event::Alarm_t>((i+sz)%4), msg[(i+sz)%4]});
      CHECK(err == theBuffer::OK);
    }
    for (unsigned i = 0; i < sz; ++i) {
      err = buffer.get(data);
      CHECK(err == theBuffer::OK);
      CHECK(static_cast<Event::Alarm_t>((i+halfSz)%4) == data.type());
    }

    err = buffer.get(data);
    CHECK(err == theBuffer::EMPTY);
  }
}



#endif
