#ifndef TAKEOFF
#define TAKEOFF

#include"../Load_routines/weightDifferential.h"
#include"../Sensors/Barometer/BMP085.h"
#include"../Sensors/Distance/Ultrasonics/HC-SR04.h"
#include"../Sensors/GPS/gps.h"
#include<stdint.h>
#include<stddef.h>

class UAV_TAKEOFF {
    private:
        uint8_t EXTRA_MASS_APPLIED();

        double LOG_CURRENT_GROUND_ALT();

        double LOG_CURRENT_COORD();

        uint8_t CALL_CONTROL_FOR_HOVER();

    public:
        uint8_t INIT_TAKEOFF();

};

#endif