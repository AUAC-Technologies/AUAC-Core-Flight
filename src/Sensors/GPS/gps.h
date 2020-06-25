#ifndef GPS_I
#define GPS_I

#include<TinyGPS++.h>

#define RX_PIN 0
#define TX_PIN 0

class GPS {
    private:
        TinyGPSPlus gps;
        
    public:
        double getLatitude();

        double getLongitude();

        double getapproxAltitude();

        double *getTime();

};

#endif