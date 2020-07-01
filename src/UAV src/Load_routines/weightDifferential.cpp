#include"weightDifferential.h"

double *WEIGHT_DIFF::COMPILE_STATE(){
    IMU *object = new IMU;
    double *stateVec = (double*)malloc(3);
    stateVec[0] = object -> getRollAxis();
    stateVec[1] = object -> getPitchAxis();
    stateVec[2] = object -> getYawAxis();
    delete object;
    return stateVec; 
}

 boolean WEIGHT_DIFF::STILL_WEIGHT_DIFFERENTIAL_DETECT(){

}

 boolean WEIGHT_DIFF::DYNAMIC_WEIGHT_DIFFERENTIAL_DETECT(){

}

uint8_t WEIGHT_DIFF::AREA_PLACED(){

}

uint8_t WEIGHT_DIFF::APPROX_MASS_PLACED(){

}