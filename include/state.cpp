#include "state.h"

  State::State(int _state)
    :state(_state)
  {
  }

  int State::getState()
  {
    std::lock_guard<std::mutex> lock(m_mutex);
    return this->state;
  }

  void State::writeState(int input)
  {
    std::lock_guard<std::mutex> lock(m_mutex);
    state = input;
  }
