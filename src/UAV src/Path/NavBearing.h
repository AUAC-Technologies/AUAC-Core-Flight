#ifndef NAV
#define NAV

#include<stddef.h>
#include<stdint.h>
#include<math.h>
#include"../Control/Thrust/MotorMixing/MMA.h"

class BEARING {
    private:
         //This function converts decimal degrees to radians       
		double deg2rad(double deg);

        //This function converts radians to decimal degrees 
		double rad2deg(double rad);
        
        uint8_t GET_REMOTE_COORDINATE();

        double COMPUTE_BEARING(double current_lat,double current_long,double final_lat,double final_long);

        double DISTANCE_BETWEEN(double current_lat,double current_long,double final_lat,double final_long);



};

#endif