#ifndef HCSR04
#define HCSR04

#define FORWARD_TRIG (uint8_t)0
#define FORWARD_ECHO (uint8_t)0

#define SIDE_LEFT_TRIG (uint8_t)0
#define SIDE_LEFT_ECHO (uint8_t)0

#define SIDE_RIGHT_TRIG (uint8_t)0
#define SIDE_RIGHT_ECHO (uint8_t)0

#define BACKWARDS_TRIG (uint8_t)0
#define BACKWARDS_ECHO (uint8_t)0

#include<Arduino.h>

class Ultrasonics {
    private:
        double interface(uint8_t trig,uint8_t echo);

    public:
        double getForwardFacing();

        double getSideLeft();

        double getSideRight();

        double getBackwardsFacing();

};

#endif