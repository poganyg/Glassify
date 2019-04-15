#include <stdio.h>
#include "SwitchThread.h"
#include <thread>
#include "gpio-sysfs.h"


SwitchThread::SwitchThread(State* _stateptr, int _gpio)
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


void SwitchThread::run()
{// while(prerun==0){
    prerun=gpio_poll(gpio_fd,POLL_TIMEOUT);
   while (rc==0)
  {
    rc = gpio_poll(gpio_fd, POLL_TIMEOUT);
	  printf("%d\n",rc);
  };

  prerun=0;
  rc=0;
  m_stateptr->bufferUp();
  gpio_fd_close(gpio_fd);
  gpio_unexport(gpio);
}
