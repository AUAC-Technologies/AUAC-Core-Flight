#include"Takeoff.h"

double TAKEOFF_ALTITUDE;
double *TAKEOFF_COORD = (double*)malloc(2);

//Struct to hold PID reference values
typedef struct {
    double HOVER_PITCH = 0;
    double HOVER_YAW = 0;
    double HOVER_ROLL = 0;
    double HOVER_ALT = 5;
}predeterminates;

uint8_t UAV_TAKEOFF::EXTRA_MASS_APPLIED(){
    WEIGHT_DIFF *determine = new WEIGHT_DIFF();
    if(determine -> STILL_WEIGHT_DIFFERENTIAL_DETECT()){

    }
    delete determine;
    return;
}

double UAV_TAKEOFF::LOG_CURRENT_GROUND_ALT(){
    Pressure *temp = new Pressure();
    TAKEOFF_ALTITUDE = temp -> getAltitude();
    return;
}

double UAV_TAKEOFF::LOG_CURRENT_COORD(){
    GPS *log = new GPS();
    TAKEOFF_COORD[0] = log -> getLatitude();
    TAKEOFF_COORD[1] = log -> getLongitude();
    delete log;
    return;
}

 uint8_t UAV_TAKEOFF::CALL_CONTROL_FOR_HOVER(){
     //Call Position Controller

 }

uint8_t UAV_TAKEOFF::INIT_TAKEOFF(){
    LOG_CURRENT_GROUND_ALT();

}