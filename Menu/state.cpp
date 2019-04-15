#include "state.h"

  State::State()
    :m_state(0),m_buffer(0)
  {
  }

  int State::getState()
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    return this->m_state;
  }

  void State::writeState(int input)
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    m_state = input;
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
