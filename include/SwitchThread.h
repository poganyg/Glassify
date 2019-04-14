#ifndef SWITCH_THREAD_H
#define SWITCH_THREAD_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gpio-sysfs.h"
#include "CppThread.h"
#include "state.h"
/*! @file SwitchThread.h
* @author Ross Crawford <ross.crawford1@outlook.com>
* @section Description the SwitchThread class allows a pin to be polled
*for an interupt and terminates upon the activation of this switch
*
*/
class SwitchThread : public CppThread {

public:
	#define POLL_TIMEOUT (5*1000)
/*!
 *\ brief Constructor that takes in required pointers and
 * initialises pin for gpiosysfs polling.
 * @param _stateptr is a pointer to the state outputted by the classification
 * @param _gpio is the pin the switch being polled is located on
*/
	SwitchThread(State* _stateptr, int _gpio)
		:rc(0),prerun(0),gpio(_gpio),m_stateptr(_stateptr)
	{
		wiringPiSetup();
    rc=0;
		prerun=0;
    gpio_export(gpio);
    gpio_set_dir(gpio, 0);
    gpio_set_edge(gpio, "rising");
    gpio_fd = gpio_fd_open(gpio); 
  }

private:
/*!
 *\ brief Polls Switch to deliver interupt
 */
   void run();
private:
	State* m_stateptr;
	int rc; //!< Value returned from polling (0 if there is no event, 1 if there is)
	int prerun; //Value returned from pre run due to intial interupt being returned
  int gpio_fd; //!< Address of gpio pin outputted from setup functions
  char *buf[MAX_BUF]; 
  unsigned int gpio; //!< Pin to be polled
  int len;
  int counter; //!< counter for limiting loop
 };

#endif
