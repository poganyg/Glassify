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
/**
* @brief Switch polling awaiting first input
*
* Class which polls the switch in the entry tube during rest state awaiting an intial bottle.
* This terminates when the first bottle is detected allowing classification to commence.
*/
class SwitchThread : public CppThread {

public:
	#define POLL_TIMEOUT (5*1000) //!< Amount of time before polling timeout each loop (in milliseconds)
	/*!
	* @brief Constructor that takes in required pointers and
	* initialises pin for gpiosysfs polling.
	* @param _stateptr is a pointer to the state outputted by the classification
	* @param _gpio is the pin the switch being polled is located on
	*/
	SwitchThread(State* _stateptr, int _gpio);
	int rc; //!< Value returned from polling (0 if there is no event, 1 if there is)


private:
	/*!
	* @brief Polls Switch to deliver interupt
	*/
	void run();
private:
	State* m_stateptr; //!< Declaration of state pointer
	int prerun; //!<Value returned from pre run due to intial interupt being returned
	int gpio_fd; //!< Address of gpio pin outputted from setup functions
	char *buf[MAX_BUF];
	unsigned int gpio; //!< Pin to be polled
	int len;
	int counter; //!< counter for limiting loop
};

#endif
