#include "Buttons.h"

using namespace std;

Buttons::Buttons(State* _stateptr)
:M_BUTTON1 (2), M_BUTTON2 (3), M_DEBOUNCE (50), m_stateptr(_stateptr)
{
  pinMode(M_BUTTON1, INPUT);
  pinMode(M_BUTTON2, INPUT);
  pullUpDnControl(M_BUTTON1, PUD_DOWN);
  pullUpDnControl(M_BUTTON2, PUD_DOWN);

  int testVector[1];
}

   int Buttons::buttonPress()
   {
     int* vecptr = &testVector;
     int length = sizeof(testVector);
     if(length>1){
       for(int i=0 ;i<(length-2);i++)
       {
         *vecptr[i]=*vecptr[i+1];
       }
     }
   }
