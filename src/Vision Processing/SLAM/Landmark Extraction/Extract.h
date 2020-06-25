#ifndef L_EXTRACT
#define L_EXTRACT

//#include"../../../lidar/LIDAR_LITE_V3.h"
#include<Arduino.h>

class EXTRACTION {
    private:
        //Function to push lidar distance and angle value 
        double *dataPush();

        double SAR_to_angle(double SAR);

    public:
        double *updateMap(double **map);


};

#endif