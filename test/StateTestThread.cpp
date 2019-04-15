#include "StateTestThread.h"

void StateTestThread::run()
{
	for(int i=0;i<1000;i++)
	{
		m_buffer=m_stateptr->getBuffer();
		m_state=m_stateptr->getState();
		m_stateptr->writeState(i);
		m_stateptr->bufferUp();
		m_stateptr->bufferDown();
	}
}
