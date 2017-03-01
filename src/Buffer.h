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

class Buffer
{
public:
  typedef int Elem_Ty;
  enum Error : unsigned char {OK, FULL, EMPTY};

  Buffer();

  Error add(const Elem_Ty& value);
  Error get(Elem_Ty& value);
  bool isEmpty() const;

private:
  unsigned int read;
  unsigned int write;
  size_t       numItems;

  static const size_t sz = 16;
  Elem_Ty buffer[sz];
};



#endif /* BUFFER_H_ */
