// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// IFilter.h
//
// ------------------------------------------------------------
#ifndef IFILTER_H_
#define IFILTER_H_

#include <string>

class I_Filter
{
public:
  virtual std::string execute() = 0;
  virtual ~I_Filter() = default;
};

#endif /* IFILTER_H_ */
