#ifndef WEIGHTDIFF
#define WEIGHTDIFF

#include<stddef.h>
#include<stdint.h>
#include<Arduino.h>

class WEIGHT_DIFF{
    public:
        boolean STILL_WEIGHT_DIFFERENTIAL_DETECT();

        boolean DYNAMIC_WEIGHT_DIFFERENTIAL_DETECT();

        uint8_t AREA_PLACED();

        uint8_t APPROX_MASS_PLACED();

        uint8_t UPDATE_CG();


};

#endif