/*MIT License

Copyright (c) 2020 Nyameaama Gambrah

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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