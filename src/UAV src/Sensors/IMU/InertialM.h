#ifndef InertialM
#define InertialM

//#include"../../../lib/i2cdevlib-master/Arduino/MPU6050/MPU6050.h"
//#include"MPU6050.h"
//#include"MPU6050_6Axis_MotionApps20.h"

class IMU {
    private:
        void setOffsets();

        void dmpInitError();

        void MPUMath();

    public:
        IMU();

        void MPU6050Connect();

        double getPitchAxis();

        double getYawAxis();

        double getRollAxis();

        void GetDMP();
};

#endif