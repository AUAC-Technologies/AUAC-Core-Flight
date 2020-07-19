#include"EventQueue.h"

uint8_t EVENT_QUEUE::UAV_SETUP(){

}


uint8_t EVENT_QUEUE::BEGIN_HOVER(){
    UAV_TAKEOFF *hover = new UAV_TAKEOFF;
    hover -> INIT_TAKEOFF();
    delete hover;
    return;
}