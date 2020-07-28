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
