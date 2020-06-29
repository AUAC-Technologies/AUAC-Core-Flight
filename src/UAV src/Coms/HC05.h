#ifndef HC05BT
#define HC05BT

#include<SoftwareSerial.h>

#define RX_PIN 0
#define TX_PIN 0

class HC05 {
    private:
        String compressStrings(String x, String y);

        String *decompressString(String x);

    public:
        HC05();


};

#endif