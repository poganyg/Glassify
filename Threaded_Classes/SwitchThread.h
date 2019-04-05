#ifndef SWITCH_THREAD_H
#define SWITCH_THREAD_H

#include "CppThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class SwitchThread : public CppThread {

public:
	SwitchThread(int SwitchPin){
		gpio = atoi(argv[1]);
	  gpio_export(gpio);
	  gpio_set_dir(gpio, 0);
	  gpio_set_edge(gpio, "falling");
	  gpio_fd = gpio_fd_open(gpio);
}
private:
   int PollSwitch(){
	 }
 private:

	 int gpio_fd;
	 char *buf[MAX_BUF];
	 unsigned int gpio;
	 int len;
	 int rc;
	 int counter;
	 motorMove shift;
	 AcqClassImages cam;
 };


	#endif
