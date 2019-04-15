#include "Buttons.h"

using namespace std;

Buttons::Buttons(State* _stateptr)
:M_BUTTON1 (2), M_BUTTON2 (3), M_DEBOUNCE (50), m_stateptr(_stateptr)
{
  pinMode(M_BUTTON1, INPUT);
  pinMode(M_BUTTON2, INPUT);
  pullUpDnControl(M_BUTTON1, PUD_DOWN);
  pullUpDnControl(M_BUTTON2, PUD_DOWN);
}

   int Buttons::buttonPress()
   {
     int whichButton = 5;
     while (m_stateptr->getBuffer()==0 && m_stateptr->getState()==0 && whichButton==5)
     {
       bool debounce = true;
       int b1 = digitalRead(M_BUTTON1);
       int b2 = digitalRead(M_BUTTON2);
       if(b1==1 || b2==1)
       {
         std::this_thread::sleep_for(std::chrono::milliseconds(M_DEBOUNCE));
         if(b1==1 || b2==1)
         {debounce=false;}
       }
       if (debounce == false){
         auto start = chrono::steady_clock::now();
         if(b1==1 && b2==1)
         {
           whichButton = 1;
         }
         else if(b1==1 && b2==0)
         {
           whichButton = 1;
         }
         else if(b1==0 && b2==1)
         {
           whichButton = 2;
         }
         while (m_stateptr->getBuffer()==0 && m_stateptr->getState()==0 && (b1==1 || b2==1))
         {
           b1 = digitalRead(M_BUTTON1);
           b2 = digitalRead(M_BUTTON2);
           auto end = chrono::steady_clock::now();
           if (((chrono::duration_cast<chrono::seconds>(end - start).count())>1) && ((chrono::duration_cast<chrono::seconds>(end - start).count())<10))
           {
             whichButton = 3;
           }
           if (chrono::duration_cast<chrono::seconds>(end - start).count()>10)
           {
             whichButton = 0;
             break;
           }
         }
       }
     }
     if (m_stateptr->getBuffer()!=0 && m_stateptr->getState()!=0)
     {
       whichButton = 0;
       while (m_stateptr->getBuffer()!=0 && m_stateptr->getState()!=0)
       {
         std::this_thread::sleep_for(std::chrono::milliseconds(500));
       }
     }
     return whichButton;
   }
