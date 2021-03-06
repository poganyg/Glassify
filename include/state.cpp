#include "state.h"

  State::State()
    :m_state(0),m_buffer(0)
  {
  }

  int State::getState()
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    return m_state;
  }

  void State::writeState(int input)
  {
    std::lock_guard<std::mutex> lock(m_stateMutex);
    m_state = input;
  }

  int State::getBuffer()
  {
    std::lock_guard<std::mutex> lock(m_bufferMutex);
    return m_buffer;
  }

  void State::bufferUp()
  {
    std::lock_guard<std::mutex> lock(m_bufferMutex);
    m_buffer = m_buffer + 1;
  }

  void State::bufferDown()
  {
    std::lock_guard<std::mutex> lock(m_bufferMutex);
    m_buffer = m_buffer - 1;
  }
