#ifndef MOTOR_THREAD_H
#define MOTOR_THREAD_H
#include "CppThread.h"
#include "state.h"
#include "Classifier.h"

class ClassifierThread : public CppThread {

public:
  ClassifierThread(Classifier* _classifierptr);

private:
  void run();

private:
Classifier* classifierptr;
};
#endif
