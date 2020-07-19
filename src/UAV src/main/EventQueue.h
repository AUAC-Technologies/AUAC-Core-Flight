#ifndef EVENT
#define EVENT

#include<stdint.h>
#include<stddef.h>
#include"Takeoff.h"
//#includ

class EVENT_QUEUE {
    private:
        
    public:
        uint8_t UAV_SETUP();

        uint8_t BEGIN_HOVER();

        uint8_t INIT_GUIDANCE_NAV();

        uint8_t INIT_BLUETOOTH();
        
        

};

#endif 