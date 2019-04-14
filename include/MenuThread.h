#ifndef MENU_THREAD_H
#define MENU_THREAD_H
#include "CppThread.h"
#include "Menu.h"

//#include <wiringPi.h>
/**
* @file MenuThread.h
* @brief This header file contains all definitions relating to the
* use of the menu as a thread
* @author Reuben Docea
* @date 10/04/2019
*/
/**
* @brief Threadable implementation of menu
*/
class MenuThread : public CppThread {

public:
  /**
  @brief constructor that initialises the pointer to the Menu class
  @param _menuptr pointer to menu class
*/
  MenuThread(Menu* _menuptr);

private:
/**
* @brief Runs the menu function resulting in menu opening and being interactable with
*/
  void run();

private:
Menu* m_menuptr; //!< instance of the menu pointer in this class
};
#endif
