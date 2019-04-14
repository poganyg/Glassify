/** 
 * @file ActivePollThread.h
 * @brief Polls the switch while the classification is active to give a buffer value of the number of bottles in the tube. This prevents the classification from stopping to early
*/

#ifndef ACTIVEPOLL_THREAD_H
#define ACTIVEPOLL_THREAD_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gpio-sysfs.h"
#include "CppThread.h"
#include "state.h"

class ActivePollThread : public CppThread {

public:
	#define POLL_TIMEOUT (5*1000)
	/**
 	* Contructor that takes in state pointer and the pin the switch is located on
	* @param[in] _stateptr Pointer to the state 
   	* @param[in] _gpio pin the switch is located on
	*/
	ActivePollThread(State* _stateptr, int _gpio)
		:rc(0),prerun(0),gpio(_gpio),m_stateptr(_stateptr)
	{
    rc=0;
		prerun=0;
    gpio_export(gpio);
    gpio_set_dir(gpio, 0);
    gpio_set_edge(gpio, "rising");
    gpio_fd = gpio_fd_open(gpio);
  }

private:
	/**
	* Function which carries out polling during classification
	* @param rc Value outputted by polling (0 if no event, 1 if there is one)
	* @param prerun variable to absorb intial interupt that appears when polling begins
	* @param m_stateptr pointer to state to allow it to be set
	* @param POLL_TIMEOUT amount of time for a single loop of polling if there is no interupt
	* @param gpio_fd address for gpio pin outputted
	*/
   void run();
private:
	State* m_stateptr;
	int rc;
	int prerun;
  int gpio_fd;
  char *buf[MAX_BUF];
  unsigned int gpio;
  int len;
  int counter;
 };

#endif
