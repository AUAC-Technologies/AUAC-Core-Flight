#ifndef NAV
#define NAV

#include<stddef.h>
#include<stdint.h>
#include<math.h>
#include"../utility/utiltiyFunctions.h"
#include"../Control/Thrust/MotorMixing/MMA.h"

class BEARING {
    private:
        uint8_t GET_REMOTE_COORDINATE();

        double COMPUTE_BEARING(double current_lat,double current_long,double final_lat,double final_long);

        double DISTANCE_BETWEEN(double current_lat,double current_long,double final_lat,double final_long);

};

#endif