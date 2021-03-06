// ----------------------------------------------------------------------------------
// Buffer.cpp
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

#include "Buffer.h"



//###################################################################################
#ifdef BUFFER_WITH_DOCTEST


//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("[int buffer] testing buffer") {
  using testType = unsigned;
  constexpr unsigned sz = 32;
  constexpr unsigned halfSz = sz / 2;
  using theBuffer = Buffer<testType, sz>;
  theBuffer buffer;
  theBuffer::Error err;

  // if a REQUIRE() fails - execution of the test stops.
  REQUIRE(buffer.isEmpty() == true); 
  REQUIRE(buffer.size() == size_t(0));

  SUBCASE("added element") {
    err = buffer.add(10);
    //  If a CHECK() fails - the test is marked as failed but the execution continues
    CHECK(buffer.isEmpty() == false);
    CHECK(buffer.size() == size_t(1));
    CHECK(err == theBuffer::OK);
  }
  SUBCASE("test_initial_get") {
    testType data;
    err = buffer.get(data);

    CHECK(err == theBuffer::EMPTY);
  }

  SUBCASE("test_initial_putget") {
    err = buffer.add(1);
    testType data;
    err = buffer.get(data);

    CHECK(err == theBuffer::OK);
    CHECK(true == buffer.isEmpty());
    CHECK(buffer.size() == size_t(0));
    CHECK(1 == data);
  }

  SUBCASE("test_initial_buffer_full") {
    for (testType i = 0; i < sz; ++i) {
      err = buffer.add(i);
      CHECK(err == theBuffer::OK);
    }
    CHECK(buffer.size() == size_t(sz));
    err = buffer.add(1);

    CHECK(err == theBuffer::FULL);
  }

  SUBCASE("test_initial_buffer_full_to_empty") {
    testType data;

    for (testType i = 0; i < sz; ++i) {
      err = buffer.add(i);
      CHECK(err == theBuffer::OK);
    }
    for (testType i = 0; i < halfSz; ++i) {
      err = buffer.get(data);
      CHECK(err == theBuffer::OK);
      CHECK(i == data);
    }
    for (testType i = 0; i < halfSz; ++i) {
      err = buffer.add(i+sz);
      CHECK(err == theBuffer::OK);
    }
    for (testType i = 0; i < sz; ++i) {
      err = buffer.get(data);
      CHECK(err == theBuffer::OK);
      CHECK((i+halfSz) == data);
    }

    err = buffer.get(data);
    CHECK(err == theBuffer::EMPTY);
  }
}

#include "Event.h"


#endif
