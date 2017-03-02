// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// IRunnable.h
//
// ------------------------------------------------------------
#ifndef SRC_IRUNNABLE_H_
#define SRC_IRUNNABLE_H_

class IRunnable
{
public:
  virtual void run () = 0;
  virtual ~IRunnable() = default;
};



#endif /* SRC_IRUNNABLE_H_ */
