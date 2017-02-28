// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Pipeline.h
//
// ------------------------------------------------------------
#ifndef SRC_PIPELINE_H_
#define SRC_PIPELINE_H_

#include <vector>

class I_Filter;

class Pipeline
{
public:
  virtual ~Pipeline() = default;
  Pipeline() = default;
  void add(I_Filter&);
  void run();
private:
  std::vector<I_Filter*> pipeline;
};

#endif /* SRC_PIPELINE_H_ */
