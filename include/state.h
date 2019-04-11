#ifndef STATE
#define STATE

#include <thread>
#include <mutex>

class State {
private:
  std::mutex m_mutex;
  int state;
public:
  State(int _state);
  int getState();
  void writeState(int input);
};

#endif
