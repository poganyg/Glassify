#include "state.h"
#include "StateTestThread.h"

int main()
{
  State state;
  State* stateptr = &state;
  StateTestThread stateTestThread1(stateptr);
  StateTestThread stateTestThread2(stateptr);
  StateTestThread stateTestThread3(stateptr);
  StateTestThread stateTestThread4(stateptr);
  if (state.getState()!=0){assert_print("State::State() constructor does not initialise 'm_state' to 0")}
  if (state.getBuffer()!=0){assert_print("State::State() constructor does not initialise 'm_buffer' to 0")}

  state.bufferUp();
  if (state.getBuffer()!=1){assert_print("State::bufferUp() fails to raise 'm_buffer' by 1")}
  state.bufferDown();
  if (state.getBuffer()!=0){assert_print("State::bufferDown() fails to reduce 'm_buffer' by 1")}

  state.writeState(99);
  if (state.getState()!=99){assert_print("State::writeState() fails to set 'm_state' to inputted value")}

  stateTestThread1.start();
  stateTestThread2.start();
  stateTestThread3.start();
  stateTestThread4.start();
  stateTestThread1.join();
  stateTestThread2.join();
  stateTestThread3.join();
  stateTestThread4.join();
}
