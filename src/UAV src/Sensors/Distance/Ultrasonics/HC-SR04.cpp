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

#include"HC-SR04.h"

AUAC_BASE_DOUBLE Ultrasonics::getForwardFacing(){
    return interface(FORWARD_TRIG,FORWARD_ECHO);
}

AUAC_BASE_DOUBLE Ultrasonics::getSideLeft(){
     return interface(SIDE_LEFT_TRIG,SIDE_LEFT_ECHO);
}

AUAC_BASE_DOUBLE Ultrasonics::getSideRight(){
     return interface(SIDE_RIGHT_TRIG,SIDE_RIGHT_ECHO);
}


AUAC_BASE_DOUBLE Ultrasonics::getBackwardsFacing(){
     return interface(BACKWARDS_TRIG,BACKWARDS_ECHO);
}

AUAC_BASE_DOUBLE Ultrasonics::interface(uint8_t trig, uint8_t echo){
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