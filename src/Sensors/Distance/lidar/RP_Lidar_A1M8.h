#ifndef RP_LIDAR_A1M8
#define RP_LIDAR_A1M8

#include"../../lib/rplidar_arduino-master/RPLidarDriver/RPLidar.h"

#define RPLIDAR_MOTOR 3 // The PWM pin for control the speed of RPLIDAR's motor.
                        // This pin should connected with the RPLIDAR's MOTOCTRL signal 
                       
class RP_LIDAR {
    public:
       RP_LIDAR();

        uint8_t RP_RETURN();
};

#endif
