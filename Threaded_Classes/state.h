#ifndef STATE
#define STATE
//DONE

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
    //printf("testvar = %i\n",testvar);
    //printf("in getState\n");
    std::lock_guard<std::mutex> lock(m_mutex);
    //printf("in getState Passed Lock\n");
    return this->state;
  }
  void writeState(int input){
    //printf("testvar = %i\n",testvar);
    //printf("in writeState\n");
    std::lock_guard<std::mutex> lock(m_mutex);
    //printf("in writeState Passed Lock\n");
    state = input;
  }
};

#endif
