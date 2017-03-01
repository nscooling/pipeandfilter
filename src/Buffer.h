// ----------------------------------------------------------------------------------
// Buffer.h
// 
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any warranty
// of the item whatsoever, whether express, implied, or statutory, including, but
// not limited to, any warranty of merchantability or fitness for a particular
// purpose or any warranty that the contents of the item will be error-free.
// In no respect shall Feabhas incur any liability for any damages, including, but
// limited to, direct, indirect, special, or consequential damages arising out of,
// resulting from, or any way connected to the use of the item, whether or not
// based upon warranty, contract, tort, or otherwise; whether or not injury was
// sustained by persons or property or otherwise; and whether or not loss was
// sustained from, or arose out of, the results of, the item, or any services that
// may be provided by Feabhas.
// ----------------------------------------------------------------------------------

#ifndef BUFFER_H_
#define BUFFER_H_

#include <cstddef>
using std::size_t;

#include <array>

template <typename T, unsigned sz = 16>
class Buffer
{
public:
  using Elem_Ty = T;
  enum Error : unsigned char {OK, FULL, EMPTY};

  Buffer();

  Error add(const Elem_Ty& value);
  Error add(Elem_Ty&& value);
  Error get(Elem_Ty& value);
  bool isEmpty() const;
  bool isFull() const { return !isEmpty(); }
  size_t size() { return numItems; }

private:
  unsigned int read;
  unsigned int write;
  size_t       numItems;

//  static const size_t sz = 16;
//  Elem_Ty buffer[sz];
  std::array<Elem_Ty,sz> buffer{};
};

template <typename T, unsigned sz>
Buffer<T, sz>::Buffer() : read(0), write(0), numItems(0) {}

template <typename T, unsigned sz>
typename Buffer<T, sz>::Error Buffer<T, sz>::add(const Buffer<T, sz>::Elem_Ty &value) {
  if (numItems == sz)
    return FULL;

  buffer[write] = value;
  ++numItems;
  ++write;
  if (write == sz)
    write = 0;

  return OK;
}

template <typename T, unsigned sz>
typename Buffer<T, sz>::Error Buffer<T, sz>::add(Buffer<T, sz>::Elem_Ty &&value) {
  if (numItems == sz)
    return FULL;

  buffer[write] = std::move(value);
  ++numItems;
  ++write;
  if (write == sz)
    write = 0;

  return OK;
}

template <typename T, unsigned sz>
typename Buffer<T, sz>::Error Buffer<T, sz>::get(Buffer<T, sz>::Elem_Ty &value) {
  if (numItems == 0)
    return EMPTY;

  value = std::move(buffer[read]);
  --numItems;
  ++read;
  if (read == sz)
    read = 0;

  return OK;
}

template <typename T, unsigned sz>
bool Buffer<T, sz>::isEmpty() const { return (numItems == 0); }


#endif /* BUFFER_H_ */
