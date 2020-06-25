#include"HC-SR04.h"

double Ultrasonics::getForwardFacing(){
    return interface(FORWARD_TRIG,FORWARD_ECHO);
}

double Ultrasonics::getSideLeft(){
     return interface(SIDE_LEFT_TRIG,SIDE_LEFT_ECHO);
}

double Ultrasonics::getSideRight(){
     return interface(SIDE_RIGHT_TRIG,SIDE_RIGHT_ECHO);
}


double Ultrasonics::getBackwardsFacing(){
     return interface(BACKWARDS_TRIG,BACKWARDS_ECHO);
}

double Ultrasonics::interface(uint8_t trig, uint8_t echo){
    long duration, microseconds_to_cm;
	pinMode(trig, OUTPUT);
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	pinMode(echo, INPUT);
	duration = pulseIn(echo, HIGH);
	microseconds_to_cm = duration / 29 / 2;
	return microseconds_to_cm;
}