#ifndef NEWSWITCH
#define NEWSWITCH

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <state.h>
// Use GPIO Pin 17, which is Pin 0 for wiringPi library

#define BOTTLE_PIN 0
// the event counter

class BottleSwitch
{
BottleSwitch(_stateptr);
  // sets up the wiringPi library
  // set Pin 17/0 generate an interrupt on high-to-low transitions
  // and attach myInterrupt() to the interrupt


// -------------------------------------------------------------------------
// myInterrupt:  called every time an event occurs
void myInterrupt(void);

// -------------------------------------------------------------------------
// main
void Poll(void) {
  while ( eventCounter ==0  ) {
    printf( "%d\n", eventCounter );
  }
  eventCounter = 0;
  m_stateptr->bufferUp();
  return 0;
}
}

#endif
