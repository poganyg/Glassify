#include "gpio-sysfs.h"

void PollSwitch(){
  do {
    rc = gpio_poll(gpio_fd, POLL_TIMEOUT);
  } while (rc==0);
  }
}
