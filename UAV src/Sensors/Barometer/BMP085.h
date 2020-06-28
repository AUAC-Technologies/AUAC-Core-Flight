#ifndef BMP085
#define BMP085

#include<Adafruit_BMP085.h>

class Pressure {
    private:
        Adafruit_BMP085 Psensor;

    public:
        double getTemperature();

        double getSLPressure();

        double getPressure();

        double getAltitude();

};

#endif