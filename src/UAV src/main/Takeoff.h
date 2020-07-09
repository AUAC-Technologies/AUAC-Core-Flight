#ifndef TAKEOFF
#define TAKEOFF

#include"../Load_routines/weightDifferential.h"

class UAV_TAKEOFF {
    private:
        uint8_t EXTRA_MASS_APPLIED();

    public:
        uint8_t INIT_TAKEOFF();


};

#endif