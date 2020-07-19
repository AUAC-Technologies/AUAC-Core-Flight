#ifndef SYS
#define SYS

#include<Arduino.h>
#include<SoftwareSerial.h>
#include<SPI.h>
#include"SD.h"
#include"../../Sensors/GPS/gps.h"
#include"../../Sensors/Distance/Ultrasonics/HC-SR04.h"
#include"../../Sensors/Barometer/BMP085.h"
#include"../../Sensors/IMU/InertialM.h"
#include"../../Coms/HC05.h"

#define  PIN_OUTPUT 0
#define UNDEFINED 0

class Inspect {
    private:
         String *PNames = (String*)malloc(7);
    public:
        boolean altitudeCheck();

        boolean IMU_ProcessCheck();

        boolean GPSCheck();

        boolean BTCheck();

        boolean SDCheck();

        uint8_t *iterThrough();

        String *InspectMain();

        Inspect();
};

#endif