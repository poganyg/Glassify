#ifndef STATE
#define STATE

#include <thread>
#include <mutex>

class State {
private:
  std::mutex m_stateMutex;
  std::mutex m_bufferMutex;
  int m_state;
  int m_buffer;
public:
  State();
  int getState();
  void writeState(int input);
  int getBuffer();
  void bufferUp();
  void bufferDown();
};

#endif
