#include <thread>
#include <iostream>
#include "ClassifierThread.h"

ClassifierThread::ClassifierThread(Classifier* _classifierptr)
	:m_classifierptr(_classifierptr)
{
}

void ClassifierThread::run()
{
	m_classifierptr->classify();
}
