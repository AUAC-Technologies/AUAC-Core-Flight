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

#include"Takeoff.h"

double TAKEOFF_ALTITUDE;
double *TAKEOFF_COORD = (double*)malloc(2);

//Struct to hold PID reference values
typedef struct {
    double HOVER_PITCH = 0;
    double HOVER_YAW = 0;
    double HOVER_ROLL = 0;
    double HOVER_ALT = 5;
}predeterminates;

uint8_t UAV_TAKEOFF::EXTRA_MASS_APPLIED(){
    WEIGHT_DIFF *determine = new WEIGHT_DIFF();
    if(determine -> STILL_WEIGHT_DIFFERENTIAL_DETECT()){

    }
    delete determine;
    return;
}

double UAV_TAKEOFF::LOG_CURRENT_GROUND_ALT(){
    Pressure *temp = new Pressure();
    TAKEOFF_ALTITUDE = temp -> getAltitude();
    return;
}

double UAV_TAKEOFF::LOG_CURRENT_COORD(){
    GPS *log = new GPS();
    TAKEOFF_COORD[0] = log -> getLatitude();
    TAKEOFF_COORD[1] = log -> getLongitude();
    delete log;
    return;
}

 uint8_t UAV_TAKEOFF::CALL_CONTROL_FOR_HOVER(){
     //Call Position Controller

 }

uint8_t UAV_TAKEOFF::INIT_TAKEOFF(){
    LOG_CURRENT_GROUND_ALT();

}