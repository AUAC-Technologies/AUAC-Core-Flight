#ifndef OBS_MAP
#define OBS_MAP

#include<stddef.h>
#include<stdint.h>
#include<math.h>
#include"../../Sensors/GPS/gps.h"
#include"../../Sensors/IMU/InertialM.h"

class OBSTACLE_MAP {
    private:
        double GET_ATLTITUDE();

        double *GET_DOF();

        double AVT_STATISTICAL_FILTERING(double *set);

        double STANDARD_DEVIATION(double *array);

        double AVERAGE_FILTER(double *array);

        double *DETERMINE_LATLONG_FROM_DIST(double initiallatitude, double initiallongitude,double bearing, double metres);

        double TRIANGULATE_MEASURED_VALUE_ALTITUDE(double bearing,double reading);

        double TRIANGULATE_MEASURED_VALUE_WORLD_BEARING(double bearing,double reading);

    public:
        uint8_t UPDATE_OBS_MAP(double bearing,double reading);

};

#endif