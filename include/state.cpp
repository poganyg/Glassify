#include "state.h"

  State::State()
    :m_state{0,0,0},m_lag{0,0,0},m_buffer(0)
  {
  }

  int State::getState()
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    return this->m_state[0];
  }

  int State::getLag()
  {
    std::lock_guard<std::mutex> lock(m_lagMutex);
    return this->lag[0];
  }
/*
  void State::writeState(int input)
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    m_state = input;
  }
*/
  void State::addState(int stateIn, int lagIn)
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    std::lock_guard<std::mutex> lock(m_lagMutex);
    if(m_state[0]==0 && m_lag[0]==0)
    {
      m_state[0]=stateIn;
      m_lag[0]=lagIn;
    }
    else if(m_state[1]==0 && m_lag[1]==0)
    {
      m_state[1]=stateIn;
      m_lag[1]=lagIn;
    }
    else if(m_state[2]==0 && m_lag[2]==0)
    {
      m_state[2]=stateIn;
      m_lag[2]=lagIn;
    }
  }

  void State::removeState()
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    std::lock_guard<std::mutex> lock(m_lagMutex);
    m_state[0]=m_state[1];
    m_state[1]=m_state[2];
    m_state[2]=0;
    m_lag[0]=m_lag[1];
    m_lag[1]=m_lag[2];
    m_lag[2]=0;
  }

  int State::getBuffer()
  {
    std::lock_guard<std::mutex> lock(m_bufferMutex);
    return this->m_buffer;
  }

  void State::bufferUp()
  {
    std::lock_guard<std::mutex> lock(m_bufferMutex);
    this->m_buffer = this->m_buffer + 1;
  }

  void State::bufferDown()
  {
    std::lock_guard<std::mutex> lock(m_bufferMutex);
    this->m_buffer = this->m_buffer - 1;
  }
