// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// IDFilter.h
//
// ------------------------------------------------------------
#ifndef IDFILTER_H_
#define IDFILTER_H_

#include "IFilter.h"

class Pipe;

class IDFilter: public I_Filter
{
public:
  IDFilter(Pipe& ip, Pipe& op);
  virtual ~IDFilter();
  std::string execute() override;
private:
  Pipe* source;
  Pipe* sink;
};


#endif /* IDFILTER_H_ */
