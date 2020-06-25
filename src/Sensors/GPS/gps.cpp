#include"gps.h"

 // The serial connection to the GPS device
SoftwareSerial ss(RX_PIN, TX_PIN);

GPS::GPS(){
    ss.begin(GPSBaud);
}

double GPS::getLatitude(){
    double lat = -1;
    while(ss.available() > 0){
        gps.encode(ss.read());
		if(gps.location.isUpdated()){
            lat = gps.location.lat();
        }    
    } 
    return lat;   
}

double GPS::getLongitude(){
    double Llong = -1;
    while(ss.available() > 0){
        gps.encode(ss.read());
        if (gps.location.isUpdated()){
            Llong = gps.location.lng();
        }  
    } 
    return Llong;
}

double GPS::getapproxAltitude(){
    double approxA = -1;
    while(ss.available() > 0){
        gps.encode(ss.read());
        approxA = gps.altitude.meters();
    }
    return approxA; 
}

double *GPS::getTime(){
    double *time = (double*)malloc(3);
    while(ss.available() > 0){
        gps.encode(ss.read());
        time[0] = gps.time.hour();
        time[1] = gps.time.minute();
        time[2] = gps.time.second();
    } 
    return time;
}