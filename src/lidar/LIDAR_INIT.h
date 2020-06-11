#ifndef LIDAR
#define LIDAR

#include<Arduino.h>
#include<Servo.h>
#include<Wire.h>

#define LIDARLite_ADDRESS 0x62 // Default I2C Address of LIDAR-Lite.
#define RegisterMeasure 0x00 // Register to write to initiate ranging.
#define MeasureValue 0x04 // Value to initiate ranging.
#define RegisterHighLowB 0x8f // Register to get both High and Low bytes in 1 call.

class INIT_LIDAR {
    private:
        Servo control;
    public:
        INIT_LIDAR();
    private:

        uint8_t lidarGetRange();

        int incrementServoRotation(int x);

    public:
        uint8_t *GET_L_VALUE();

};


#endif