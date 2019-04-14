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
  constructor that initialises the pointer to the Menu class
  @param[in] _menuptr pointer to menu class
  @param m_menptr instance of the menu pointer in this class
*/
  MenuThread(Menu* _menuptr);

private:
/** 
* Runs the menu function resulting in menu opening and being interactable with 
*/
  void run();

private:
Menu* m_menuptr;
};
#endif
