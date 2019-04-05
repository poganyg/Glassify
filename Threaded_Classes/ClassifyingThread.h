#ifndef CLASSIFYING_THREAD_H
#define CLASSIFYING_THREAD_H

#include "CppThread.h"

class ClassifyingThread : public CppThread {

public:
  ClassifyingThread(int* inp)
  :Output(inp)
  {
  }

private:
  void run();
private:
  int* Output
};
#endif
