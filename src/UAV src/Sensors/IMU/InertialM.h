#ifndef InertialM
#define InertialM

//#include"../../../lib/i2cdevlib-master/Arduino/MPU6050/MPU6050.h"

class IMU {
    public:
        double getPitchAxis();

        double getYawAxis();

        double getRollAxis();


};

#endif