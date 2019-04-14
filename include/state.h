/** @file state.h
 * @brief Class containing state variable that declares if the classification is running and if a certain type of glass has been identified
 */ 
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
  /**
   * Contructor sets state and buffer to zero
   * @param m_state the state the system is in: green detected, brown detected, clear glass or resting
   * @param m_buffer shows the number of bottles in the pipe
   */
  State();
  /**
   * Outputs state to thread calling it
   * Mutex prevents segmentation fault from reading and writing being attempted simultaneously
   * @return m_state the state the system is in: green detected, brown detected, clear detected or rest
   */ 
  int getState();
  /**
   * Writes state value 
   * @param input value for state to be set to
   */
  void writeState(int input);
  /**
   * Gets buffer value for the thread calling it
   * @return m_buffer number of bottles in the tube
   */
  int getBuffer();
  /** 
   * Increases buffer by 1
   * @param m_buffer number of bottles in the tube
   */
  void bufferUp();
  /**
   * Decreases buffer by 1
   * @param m_buffer number of bottles in the tube
   */
  void bufferDown();
};

#endif
