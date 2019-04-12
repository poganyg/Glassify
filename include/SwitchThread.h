#ifndef SWITCH_THREAD_H
#define SWITCH_THREAD_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gpio-sysfs.h"
#include "CppThread.h"
#include "state.h"

class SwitchThread : public CppThread {

public:
	#define POLL_TIMEOUT (5*1000)
	SwitchThread(State* _stateptr, int _gpio)
		:rc(0),prerun(0),gpio(_gpio),m_stateptr(_stateptr)
	{
		wiringPiSetupGpio();
    rc=0;
		prerun=0;
    gpio_export(gpio);
    gpio_set_dir(gpio, 0);
    gpio_set_edge(gpio, "rising");
    gpio_fd = gpio_fd_open(gpio);
  }

private:
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
