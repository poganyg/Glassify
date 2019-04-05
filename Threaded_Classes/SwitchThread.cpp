#include <stdio.h>
#include "SwitchThread.h"
#include <thread>
#include "gpio-sysfs.cpp"

void SwitchThread::run(){
  do {
    rc = gpio_poll(gpio_fd, POLL_TIMEOUT);
	printf("%d\n",rc);
  } while (rc==0);
  }

