#ifndef STATE
#define STATE

#include <thread>
#include <mutex>

class State {
private:
  std::mutex m_stateMutex;
  std::mutex m_bufferMutex;
  std::mutex m_lagMutex;
  int m_lag[3];
  int m_state[3];
  int m_buffer;
public:
  State();
  int getState();
  int getLag();
  //void writeState(int input);
  void addState(int stateIn, int lagIn);
  void removeState();
  int getBuffer();
  void bufferUp();
  void bufferDown();
};

#endif
