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

#include"SYSTEM_CHECK.h"

uint8_t count;
Inspect::Inspect(){
    PNames[0] = "Altitude Module Error";
    PNames[1] = "Velocity Module Error";
    PNames[2] = "IMU Module Error";
    PNames[3] = "GPS Module Error";
    PNames[4] = "Bluetooth Module Error";
    PNames[5] = "RF Module Error";
    PNames[6] = "SD Module Error";
}

 boolean Inspect::altitudeCheck(){
    boolean check = false;
    Pressure *alt = new Pressure();
    if(alt -> getAltitude() != 0.00){
        check = true;
    }
    delete alt;
    return check;
 }

/*boolean Inspect::IMU_ProcessCheck(){
    Gyro get;
    boolean pitchState,yawState,rollState;
    pitchState = (get.AccGyroVals(2) != 0.00) ? true : false;
    yawState = (get.AccGyroVals(3) != 0.00) ? true : false;
    rollState = (get.AccGyroVals(1) != 0.00) ? true : false;
    if((pitchState) && (yawState) && (rollState)){
        return true;
    }else{
        return false;
    }
}*/

boolean Inspect::GPSCheck(){
    boolean state;
    static const uint8_t RXPin = UNDEFINED, TXPin = UNDEFINED;
	static const uint32_t GPSBaud = 9600;
    SoftwareSerial GPSserial(RXPin, TXPin);
	GPSserial.begin(GPSBaud);
    state = (GPSserial.available() <= 0) ? true : false;
    return state;
}

boolean Inspect::BTCheck(){
    static const uint8_t RX= UNDEFINED, TX = UNDEFINED;
    SoftwareSerial BlueTSerial(RX, TX); // RX | TX
    BlueTSerial.begin(38400);
    return (BlueTSerial.available() <= 0) ? true : false;
}

boolean Inspect::SDCheck(){
    return (!SD.begin(PIN_OUTPUT)) ? false: true;
}

String *Inspect::InspectMain(){
    uint8_t size = 7,count;
    uint8_t *temp = (uint8_t*)malloc(size);
    uint8_t *temp2 = (uint8_t*)malloc(size);
    //String *PNames = (String*)malloc(7);
    String *strReturn = (String*)malloc(5);
    //Descriptions
    temp2 = iterThrough();
    realloc(temp2,count + 1);
    strReturn[0] = String(count);
    //if no errors
    if(count == 0){
        strReturn[1] = "OK";
        free(temp);
        free(temp2);
        free(PNames);
        return strReturn;
    }else{
        //if errors, put in array and return
        for(size_t j = 1;j < count + 1;j++){
            strReturn[j] = PNames[temp2[j - 1]];
        }
        free(temp);
        free(temp2);
        free(PNames);
        return strReturn;
    }
}
uint8_t *Inspect::iterThrough(){
    uint8_t size = 7,count;
    uint8_t *temp = (uint8_t*)malloc(size);
    uint8_t *newTemp = (uint8_t*)malloc(size);
    uint8_t altitude,velocity,IMU,GPS,bT,RF,SD;
    //Check to see if functions return 1(denoting fail).If 
    //fail return the errors with their description
    temp[0] = altitude = (altitudeCheck()) ? 0 : 1;
    //temp[1] = velocity = (velocityCheck()) ? 0 : 1;
    //temp[2] = IMU = (IMU_ProcessCheck()) ? 0 : 1;
    temp[3] = GPS = (GPSCheck()) ? 0 : 1;
    temp[4] = bT = (BTCheck()) ? 0 : 1;
    //temp[5] = RF = (RFCheck()) ? 0 : 1;
    temp[6] = SD = (SDCheck()) ? 0 : 1;
    for(size_t i = 0; i < size;i++){
        if(temp[i] == 1){
            newTemp[count] = i;
            count++;
        }
    }
    return newTemp;
}
