#include "lcd.h"
#include "FunctioningCamera.h"
#include "ServoControl.h"
#include "libServo.cpp"
#include "libServo.h"
#include <thread>
#include <chrono>

void CapClassify(){
  int result==0;
  int colour==0;
  int moving==0;
  while (moving==0 && colour==0)
  {
  colour=cam.checkColour();
  moving=cam.checkMatch();
}
if (colour==0){
result==moving
}else{
  result==colour;
}
  return result;
}

void move(int output)
{
  if (ouput==1)
  {
    shift.isBrown();
    lcd.write("Brown Glass Detected");
  }
  if (output==2)
  {
    shift.isGreen();
    lcd.write("Green Glass Detected");
  }
  if (output==3)
  {
    shift.isWhite();
    lcd.write("White Glass Detected");
  }
}

int main(){
  int Switchpin=13;
  while(true){
    bool Switch=digitalRead(Switchpin);
if(Switch==0)
{  std::this_thread::sleep_for(std::chrono::milliseconds(200));}
else
{output=CapClassify();
  move(output);
}
}
}
