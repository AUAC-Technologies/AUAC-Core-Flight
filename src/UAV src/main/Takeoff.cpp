#include"Takeoff.h"

//Struct to hold PID reference values
typedef struct {
    double HOVER_PITCH = 0;
    double HOVER_YAW = 0;
    double HOVER_ROLL = 0;
    double HOVER_ALT = 5;
}predeterminates;

uint8_t UAV_TAKEOFF::EXTRA_MASS_APPLIED(){
    WEIGHT_DIFF *determine = new WEIGHT_DIFF;
    if(determine -> STILL_WEIGHT_DIFFERENTIAL_DETECT()){

    }
    delete determine;
    return;
}

uint8_t UAV_TAKEOFF::INIT_TAKEOFF(){
    
}