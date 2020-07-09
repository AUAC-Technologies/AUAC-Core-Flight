#ifndef MMA
#define MMA

#include<stdint.h>
#include<stddef.h>
#include"../Driver/PropThrustControl.h"

//Class for motor mixing algorithm

class MOTOR_MIXING {
    private:
        uint8_t THRUST_RANGE_FIX();

        double getCurrentThrustLevel(uint8_t MOTOR);
        
    public:
        uint8_t MOTOR_MIX_ROLL(double roll);

        uint8_t MOTOR_MIX_YAW(double yaw);

        uint8_t MOTOR_MIX_PITCH(double pitch);

        uint8_t MOTOR_MIX_THRUST(double thrustLevel);

};

#endif