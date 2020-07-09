#ifndef ILC
#define ILC

#include"Thrust/MotorMixing/MMA.h"
#include"PID/PID.h"
#include<stdint.h>
#include<stddef.h>

//PID controllers to change and maintain DOF

class InnerLoopControl {
    public:
        double ADJUST_ROLL(double set,double current);

        double ADJUST_PITCH(double set,double current);
        
        double ADJUST_YAW(double set,double current);

        

};

#endif