#include <stdio.h>
#include "SwitchThread.h"
#include <thread>
#include "gpio-sysfs.cpp"

void SwitchThread::run(){
  prerun=gpio_poll(gpio_fd,POLL_TIMEOUT);
  do {
    rc = gpio_poll(gpio_fd, POLL_TIMEOUT);
	printf("%d\n",rc);
  } while (rc==0);
  gpio_fd_close(gpio_fd);
  gpio_unexport(gpio);
  }

