/**
* @file ClassifierThread.h
* @brief Thread which uses the classification class to classify bottles
* @author Reuben Docea
*
*/
#ifndef CLASSIFIERTHREAD_H
#define CLASSIFIERTHREAD_H
#include "CppThread.h"
#include "state.h"
#include "Classifier.h"
/**
* @brief Threaded implementation of classification
*/
class ClassifierThread : public CppThread {
  /**
  * Constructor that take in classifier pointer
  * @param m_classifierptr pointer to the classification class
  */
public:
  ClassifierThread(Classifier* _classifierptr);

private:
  /**
  * Calls and runs classify function of classification class
  * @param m_classifierptr pointer to the classification class
  */
  void run();

private:
  Classifier* m_classifierptr; //!< decleration of classifier pointer
};
#endif
