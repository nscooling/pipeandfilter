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

Buffer::Buffer() : read(0), write(0), numItems(0) {}

Buffer::Error Buffer::add(const Buffer::Elem_Ty &value) {
  if (numItems == sz)
    return FULL;

  buffer[write] = value;
  ++numItems;
  ++write;
  if (write == sz)
    write = 0;

  return OK;
}

Buffer::Error Buffer::get(Buffer::Elem_Ty &value) {
  if (numItems == 0)
    return EMPTY;

  value = buffer[read];
  --numItems;
  ++read;
  if (read == sz)
    read = 0;

  return OK;
}

bool Buffer::isEmpty() const { return (numItems == 0); }


//###################################################################################
#ifdef BUFFER_WITH_DOCTEST

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("[buffer] testing buffer") {
  Buffer buffer;
  Buffer::Error err;

  // if a REQUIRE() fails - execution of the test stops.
  REQUIRE(buffer.isEmpty() == true); 

  SUBCASE("added element") {
    err = buffer.add(10);
    //  If a CHECK() fails - the test is marked as failed but the execution continues
    CHECK(buffer.isEmpty() == false);
    CHECK(err == Buffer::OK);
  }
  SUBCASE("test_initial_get") {
    int data;
    err = buffer.get(data);

    CHECK(err == Buffer::EMPTY);
  }

  SUBCASE("test_initial_putget") {
    err = buffer.add(1);
    int data;
    err = buffer.get(data);

    CHECK(err == Buffer::OK);
    CHECK(true == buffer.isEmpty());
    CHECK(1 == data);
  }

  SUBCASE("test_initial_buffer_full") {
    for (int i = 0; i < 16; ++i) {
      err = buffer.add(i);
      CHECK(err == Buffer::OK);
    }
    err = buffer.add(1);

    CHECK(err == Buffer::FULL);
  }

  SUBCASE("test_initial_buffer_full_to_empty") {
    int data;

    for (int i = 0; i < 10; ++i) {
      err = buffer.add(i);
      CHECK(err == Buffer::OK);
    }
    for (int i = 0; i < 8; ++i) {
      err = buffer.get(data);
      CHECK(err == Buffer::OK);
      CHECK(i == data);
    }
    for (int i = 10; i < 18; ++i) {
      err = buffer.add(i);
      CHECK(err == Buffer::OK);
    }
    for (int i = 8; i < 18; ++i) {
      err = buffer.get(data);
      CHECK(err == Buffer::OK);
      CHECK(i == data);
    }

    err = buffer.get(data);
    CHECK(err == Buffer::EMPTY);
  }
}

#endif
