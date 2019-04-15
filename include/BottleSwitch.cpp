#include "NewSwitch.h"
// Use GPIO Pin 17, which is Pin 0 for wiringPi library

BottleSwitch::BottleSwitch(_stateptr)
  :m_stateptr(_stateptr)
{
  // sets up the wiringPi library
  if (wiringPiSetup () < 0) {
      fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror (errno));
      return 1;
  }

  // set Pin 17/0 generate an interrupt on high-to-low transitions
  // and attach myInterrupt() to the interrupt
  if ( wiringPiISR (BOTTLE_PIN, INT_EDGE_FALLING, &myInterrupt) < 0 ) {
      fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno));
      return 1;
  }
}

// -------------------------------------------------------------------------
// myInterrupt:  called every time an event occurs
void BottleSwitch::myInterrupt(void) {
   eventCounter++;
}

// -------------------------------------------------------------------------
// main
void BottleSwitch::Poll(void) {
  while ( eventCounter ==0  ) {
    printf( "%d\n", eventCounter );
  }
  eventCounter = 0;
  m_stateptr->bufferUp();
  return 0;
}
