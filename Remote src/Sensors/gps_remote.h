#ifndef GPS_REMOTE
#define GPS_REMOTE

#include<TinyGPS++.h>
#include<SoftwareSerial.h>

#define RX_PIN 0
#define TX_PIN 0

class GPS {
    private:
        TinyGPSPlus gps;
        static const uint32_t GPSBaud = 9600;
    
    public:
        //Constructor
        GPS();

        //Function to get latitude from GPS
        double getLatitude();

        //Function to get longitude from GPS
        double getLongitude();

        //Function to get approxiamate altitude from GPS
        //Returns meters
        double getapproxAltitude();

        //Function to return array of current time from GPS
        //{Hour,Min,Sec}
        double *getTime();

};

#endif