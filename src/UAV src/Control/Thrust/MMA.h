#ifndef MMA
#define MMA

#include<stdint.h>
#include<stddef.h>
#include"PropThrustControl.h"

class MOTOR_MIXING {
    private:
        uint8_t THRUST_RANGE_FIX();
        
    public:
        uint8_t MOTOR_MIX_ROLL(uint8_t roll);

        uint8_t MOTOR_MIX_YAW(uint8_t yaw);

        uint8_t MOTOR_MIX_PITCH(uint8_t pitch);

};

#endif