// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// RunnableFilter.h
//
// ------------------------------------------------------------
#ifndef SRC_RUNNABLEFILTER_H_
#define SRC_RUNNABLEFILTER_H_

#include "IRunnable.h"
#include "IFilter.h"

class RunnableFilter: public IRunnable
{
public:
  RunnableFilter(I_Filter&);
  virtual ~RunnableFilter();
  void run();
private:
  I_Filter* theFilter { nullptr };
};

#endif /* SRC_RUNNABLEFILTER_H_ */
