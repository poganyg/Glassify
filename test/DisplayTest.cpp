#include "Display.h"
#include "assert_print.h"

int main(int,char**)
{
  wiringPiSetup();
  Display display;
  if(display.m_height!=2){assert_print("Incorrect height for the 1602 LCD. Value should be 2.");}
  if(display.m_width!=16){assert_print("Incorrect width for the 1602 LCD. Value should be 16.");}
  if(display.m_bits!=4){assert_print("Incorrect number of bits for this use of the 1602 LCD. Value should be 4.");}
}
