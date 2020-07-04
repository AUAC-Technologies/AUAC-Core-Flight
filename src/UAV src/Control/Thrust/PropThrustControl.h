#include<stdint.h>
#include<stddef.h>
#include<Arduino.h>

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define BPIN1 4
#define BPIN2 5
#define BPIN3 6
#define BPIN4 7

//Propeller Thrust Rate Control
//When each of the 4 propellers velocity is adjusted, it causes a change in direction of the craft
//Using this our primary control means we can adjust the direction of yaw movement

class PropThrustControl {
    private:
        uint8_t thrustWriteFL(uint8_t PWM);

        uint8_t thrustWriteFR(uint8_t PWM);

        uint8_t thrustWriteBL(uint8_t PWM);

        uint8_t thrustWriteBR(uint8_t PWM);

        uint8_t updateThrustValues(uint8_t MOTOR, double tLevel);


    public:
        PropThrustControl();

        uint8_t PWM_init(uint8_t MOTOR,uint8_t M2_VEL);

        //Translates 0 - 9 motor PWM values to 0,175 - 255
        double translate(double x);

        double *returnCurrentThrustValues();

};