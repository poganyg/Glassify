#include <wiringPi.h>
#include <thread>
#include <iostream>
#include "MenuThread.h"

MenuThread::MenuThread(Menu* _menuptr)
	:m_menuptr(_menuptr)
{
}

void MenuThread::run()
{
	m_menuptr->mainMenu();
}
