#include"AutoConnect.h"

int HC05_OLDSTATE;   

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