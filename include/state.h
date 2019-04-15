/** @file state.h
* @brief Class containing state variable that declares if the classification is running and if a certain type of glass has been identified
*/
#ifndef STATE
#define STATE

#include <thread>
#include <mutex>
/**
* @brief Contains all interfacing for reading or setting system state
*/
class State {
private:
  std::mutex m_stateMutex; //!< Mutex variable for locking access to m_state variable
  std::mutex m_bufferMutex; //!< Mutex variable locking access to m_buffer variable
  int m_state;   //!< he state the system is in: green detected, brown detected, clear glass or resting
  int m_buffer;  //!< shows the number of bottles in the pipe
public:
  /**
  * Contructor sets state and buffer to zero
  */
  State();
  /**
  * @brief Outputs state to thread calling it
  * Mutex prevents segmentation fault from reading and writing being attempted simultaneously
  * @return m_state the state the system is in: green detected, brown detected, clear detected or rest
  */
  int getState();
  /**
  * @brief Writes state value
  * @param input value for state to be set to
  */
  void writeState(int input);
  /**
  * @brief Gets buffer value for the thread calling it
  * @return m_buffer number of bottles in the tube
  */
  int getBuffer();
  /**
  * @brief Increases buffer by 1
  */
  void bufferUp();
  /**
  * @brief Decreases buffer by 1
  */
  void bufferDown();
};

#endif
