#include"InnerLoopControl.h"

double ADJUST_ROLL(double set, double current){
    PROPORTIONAL_INTEGRAL_DERIVATIVE *control = new PROPORTIONAL_INTEGRAL_DERIVATIVE;
    MOTOR_MIXING *mix = new MOTOR_MIXING;
    double kp,kd,ki;  //<- Tune PID gains
    control -> createPIDinstance("innerLoopRoll",kp,ki,kd);
    double newR = control -> PID_MAIN("innerLoopRoll",set,current);
    mix -> MOTOR_MIX_ROLL(newR);
    delete control;
    delete mix;
    return;
}

double ADJUST_PITCH(double set, double current){
    PROPORTIONAL_INTEGRAL_DERIVATIVE *control = new PROPORTIONAL_INTEGRAL_DERIVATIVE;
    MOTOR_MIXING *mix = new MOTOR_MIXING;
    double kp,kd,ki;  //<- Tune PID gains
    control -> createPIDinstance("innerLoopPitch",kp,ki,kd);
    double newP = control -> PID_MAIN("innerLoopPitch",set,current);
    mix -> MOTOR_MIX_ROLL(newP);
    delete control;
    delete mix;
    return;
}
        
double ADJUST_YAW(double set, double current){
    PROPORTIONAL_INTEGRAL_DERIVATIVE *control = new PROPORTIONAL_INTEGRAL_DERIVATIVE;
    MOTOR_MIXING *mix = new MOTOR_MIXING;
    double kp,kd,ki; //<- Tune PID gains
    control -> createPIDinstance("innerLoopYaw",kp,ki,kd);
    double newY = control -> PID_MAIN("innerLoopYaw",set,current);
    mix -> MOTOR_MIX_ROLL(newY);
    delete control;
    delete mix;
    return;
}