#ifndef STATE
#define STATE

#include <thread>
#include <mutex>

class State {
private:
  std::mutex m_mutex;
  int state;
public:
  State(int _state)
    :state(_state)
  {
  }

  int getState(){
    std::lock_guard<std::mutex> lock(m_mutex);
    return this->state;
  }

  void writeState(int input){
    std::lock_guard<std::mutex> lock(m_mutex);
    state = input;
  }
};

#endif
