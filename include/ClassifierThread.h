#ifndef CLASSIFIERTHREAD_H
#define CLASSIFIERTHREAD_H
#include "CppThread.h"
#include "state.h"
#include "Classifier.h"

class ClassifierThread : public CppThread {

public:
  ClassifierThread(Classifier* _classifierptr);

private:
  void run();

private:
Classifier* m_classifierptr;
};
#endif
