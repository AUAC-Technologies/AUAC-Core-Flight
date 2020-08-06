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

#include"gps.h"

TinyGPSPlus gps;
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