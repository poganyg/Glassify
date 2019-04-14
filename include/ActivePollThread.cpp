#include <stdio.h>
#include "ActivePollThread.h"
#include <thread>
#include "gpio-sysfs.h"

void ActivePollThread::run()
{
  while(m_stateptr->getBuffer()!=0)
  {
    prerun=gpio_poll(gpio_fd,POLL_TIMEOUT);
    do
    {
      rc = gpio_poll(gpio_fd, POLL_TIMEOUT);
      printf("%d\n",rc);
    } while (rc==0 && m_stateptr->getBuffer()!=0);

    if(rc!=0)
    {
      m_stateptr->bufferUp();
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
  }
  gpio_fd_close(gpio_fd);
  gpio_unexport(gpio);
}
