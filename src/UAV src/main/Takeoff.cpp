#include"Takeoff.h"

uint8_t UAV_TAKEOFF::EXTRA_MASS_APPLIED(){
    WEIGHT_DIFF *determine = new WEIGHT_DIFF;
    if(determine -> STILL_WEIGHT_DIFFERENTIAL_DETECT()){

    }
    delete determine;
    return;
}