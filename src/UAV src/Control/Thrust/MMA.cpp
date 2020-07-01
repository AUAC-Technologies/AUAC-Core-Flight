#include"MMA.h"

uint8_t MOTOR_MIXING::THRUST_RANGE_FIX(){

}

uint8_t MOTOR_MIXING::MOTOR_MIX_ROLL(double roll){
    PropThrustControl *ADJUST = new PropThrustControl;
    signed int thrust;
    if(roll < 0){
        ADJUST -> PWM_init(1,thrust + roll);
        ADJUST -> PWM_init(2,thrust - roll); 
        ADJUST -> PWM_init(3,thrust + roll); 
        ADJUST -> PWM_init(4,thrust - roll);  
    }else{
        ADJUST -> PWM_init(1,thrust - roll);
        ADJUST -> PWM_init(2,thrust + roll); 
        ADJUST -> PWM_init(3,thrust - roll); 
        ADJUST -> PWM_init(4,thrust + roll); 
    }
    delete ADJUST;
    return;
}

uint8_t MOTOR_MIXING::MOTOR_MIX_YAW(double yaw){
    PropThrustControl *MOD = new PropThrustControl;
    signed int thrust;
    if(yaw < 0){
        MOD -> PWM_init(1,thrust - yaw);
        MOD -> PWM_init(2,thrust + yaw); 
        MOD -> PWM_init(3,thrust + yaw); 
        MOD -> PWM_init(4,thrust - yaw);  
    }else{
        MOD -> PWM_init(1,thrust + yaw);
        MOD -> PWM_init(2,thrust - yaw); 
        MOD -> PWM_init(3,thrust - yaw); 
        MOD -> PWM_init(4,thrust + yaw); 
    }
    delete MOD;
    return;
}

uint8_t MOTOR_MIXING::MOTOR_MIX_PITCH(double pitch){
    PropThrustControl *ALTER = new PropThrustControl;
    signed int thrust;
    if(pitch < 0){
        ALTER -> PWM_init(1,thrust + pitch);
        ALTER -> PWM_init(2,thrust + pitch); 
        ALTER -> PWM_init(3,thrust - pitch); 
        ALTER -> PWM_init(4,thrust - pitch);  
    }else{
        ALTER -> PWM_init(1,thrust - pitch);
        ALTER -> PWM_init(2,thrust - pitch); 
        ALTER -> PWM_init(3,thrust + pitch); 
        ALTER -> PWM_init(4,thrust + pitch); 
    }
    delete ALTER;
    return;
}