#ifndef CONNECT_
#define CONNECT_

/*                  HC-05 Automate Bonding with Bluetooth device
 * Description:     This assisted bonding is specifically geared towards bonding with bluetooth devices
 *                  Was written to assist automation of the process in connecting the UAV and the remote during startup
 * */
#define AT 1
#define COMMUNICATION 0
//module STATE definitions
#define DISCONNECTED  0
#define CONNECTED     1
#define HC05_STATE_PIN  12 //hc-05 state digital pin
#define HC05_KEY_PIN    13 //hc-05 key digital pin
#define HC05_EN_PIN     14 //hc-05 enable digital pin

#include<Arduino.h>

class AUTO_CONNECT {
    private:
        uint8_t Check_HC05_STATE();

        uint8_t Set_HC05_MODE(uint8_t mode);

        boolean setAT();

        boolean setCommunictaion();

    public:
        uint8_t INIT_CONNECT();



};

#endif