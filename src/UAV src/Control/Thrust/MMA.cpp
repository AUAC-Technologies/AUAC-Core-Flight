#include"MMA.h"

uint8_t MOTOR_MIXING::THRUST_RANGE_FIX(){

}

double MOTOR_MIXING::getCurrentThrustLevel(uint8_t MOTOR){
    PropThrustControl *RETRIEVE = new PropThrustControl;
    double *level = RETRIEVE -> returnCurrentThrustValues();
    double thrust = level[MOTOR - 1];
    delete RETRIEVE;
    return thrust;
}

uint8_t MOTOR_MIXING::MOTOR_MIX_ROLL(double roll){
    PropThrustControl *ADJUST = new PropThrustControl;
    if(roll < 0){
        ADJUST -> PWM_init(1,getCurrentThrustLevel(1) + roll);
        ADJUST -> PWM_init(2,getCurrentThrustLevel(2) - roll); 
        ADJUST -> PWM_init(3,getCurrentThrustLevel(3) + roll); 
        ADJUST -> PWM_init(4,getCurrentThrustLevel(4) - roll);  
    }else{
        ADJUST -> PWM_init(1,getCurrentThrustLevel(1) - roll);
        ADJUST -> PWM_init(2,getCurrentThrustLevel(2) + roll); 
        ADJUST -> PWM_init(3,getCurrentThrustLevel(3) - roll); 
        ADJUST -> PWM_init(4,getCurrentThrustLevel(4) + roll); 
    }
    delete ADJUST;
    return;
}

uint8_t MOTOR_MIXING::MOTOR_MIX_YAW(double yaw){
    PropThrustControl *MOD = new PropThrustControl;
    if(yaw < 0){
        MOD -> PWM_init(1,getCurrentThrustLevel(1) - yaw);
        MOD -> PWM_init(2,getCurrentThrustLevel(2) + yaw); 
        MOD -> PWM_init(3,getCurrentThrustLevel(3) + yaw); 
        MOD -> PWM_init(4,getCurrentThrustLevel(4) - yaw);  
    }else{
        MOD -> PWM_init(1,getCurrentThrustLevel(1) + yaw);
        MOD -> PWM_init(2,getCurrentThrustLevel(2) - yaw); 
        MOD -> PWM_init(3,getCurrentThrustLevel(3) - yaw); 
        MOD -> PWM_init(4,getCurrentThrustLevel(4) + yaw); 
    }
    delete MOD;
    return;
}

uint8_t MOTOR_MIXING::MOTOR_MIX_PITCH(double pitch){
    PropThrustControl *ALTER = new PropThrustControl;
    if(pitch < 0){
        ALTER -> PWM_init(1,getCurrentThrustLevel(1) + pitch);
        ALTER -> PWM_init(2,getCurrentThrustLevel(2) + pitch); 
        ALTER -> PWM_init(3,getCurrentThrustLevel(3) - pitch); 
        ALTER -> PWM_init(4,getCurrentThrustLevel(4) - pitch);  
    }else{
        ALTER -> PWM_init(1,getCurrentThrustLevel(1) - pitch);
        ALTER -> PWM_init(2,getCurrentThrustLevel(2) - pitch); 
        ALTER -> PWM_init(3,getCurrentThrustLevel(3) + pitch); 
        ALTER -> PWM_init(4,getCurrentThrustLevel(4) + pitch); 
    }
    delete ALTER;
    return;
}

uint8_t MOTOR_MIXING::MOTOR_MIX_THRUST(double thrustLevel){
    PropThrustControl *ALTER = new PropThrustControl;
    double thrust;
    
    delete ALTER;
    return;
}