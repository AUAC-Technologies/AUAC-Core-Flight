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