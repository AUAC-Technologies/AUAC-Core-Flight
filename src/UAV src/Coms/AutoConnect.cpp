/*MIT License

Copyright (c) 2020 Nyameaama Gambrah

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"AutoConnect.h"

int HC05_OLDSTATE;   

uint8_t AUTO_CONNECT::INIT_CONNECT(){
  if(Check_HC05_STATE() == CONNECTED){

  }
}



uint8_t AUTO_CONNECT::Check_HC05_STATE(){
  //Serial.println("Checking HC_05 connected state...");
  int state = digitalRead(HC05_STATE_PIN);
  if(state != HC05_OLDSTATE){
    HC05_OLDSTATE = state;
    if(state == CONNECTED){
      //Serial.println("HC-05 is connected to a bluetooth device.");
    }
    else if(state == DISCONNECTED){
      //Serial.println("HC-05 is disconnected from all bluetooth devices.");
    }
    //digitalWrite(LED, state);
  }
  return state;  
}

uint8_t AUTO_CONNECT::Set_HC05_MODE(uint8_t mode){
  if(mode == AT){
    setAT();
  }else if(mode == COMMUNICATION){
    setCommunictaion();
  }
}

boolean setAT(){
  digitalWrite(HC05_EN_PIN, LOW); //EN to LOW = disable (pull low to reset when changing modes!)
  //SET AT MODE
  digitalWrite(HC05_KEY_PIN, HIGH); //KEY to HIGH = full AT mode
}

boolean setCommunictaion(){
  digitalWrite(HC05_EN_PIN, LOW); //EN to LOW = disable (pull low to reset when changing modes!)
  //SET COMMUNICATION MODE
  digitalWrite(HC05_KEY_PIN, LOW); //LOW = communication mode
}
