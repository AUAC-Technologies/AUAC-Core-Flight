#include"LIDAR_LITE_V3.h"

uint8_t ServoPos;

//Constructor
LIDAR_LITE::LIDAR_LITE(){
    Servo *pointer = &control;
    pointer -> attach(5);
    // LIDAR control
    Wire.begin(); // join i2c bus
    
}

// Get a measurement from the LIDAR Lite
double LIDAR_LITE::lidarGetRange() {
    int val = -1;
    Wire.beginTransmission((int)LIDARLite_ADDRESS); // transmit to LIDAR-Lite
    Wire.write((int)RegisterMeasure); // sets register pointer to (0x00)
    Wire.write((int)MeasureValue); // sets register pointer to (0x00)
    Wire.endTransmission(); // stop transmitting
    delay(20); // Wait 20ms for transmit
    Wire.beginTransmission((int)LIDARLite_ADDRESS); // transmit to LIDAR-Lite
    Wire.write((int)RegisterHighLowB); // sets register pointer to (0x8f)
    Wire.endTransmission(); // stop transmitting
    delay(20); // Wait 20ms for transmit
    Wire.requestFrom((int)LIDARLite_ADDRESS, 2); // request 2 bytes from LIDAR-Lite
    if(2 <= Wire.available()){ // if two bytes were received 
        val = Wire.read(); // receive high byte (overwrites previous reading)
        val = val << 8; // shift high byte to be high 8 bits
        val |= Wire.read(); // receive low byte as lower 8 bits
    }
    return val;
}

//Function to increment servo position in a cycle from (-90 to 180)
int LIDAR_LITE::incrementServoRotation(int x){
    int pos = (x == 180) ? pos = -90 : x += 1;
    return pos;
}

//Function returns lidar range value with servo angular rotation (-90 to 180)
double *LIDAR_LITE::GET_L_VALUE(){
    uint8_t DLEAY_TIME;
    //Move servo by 1 degree
    control.write(ServoPos);
    delay(DLEAY_TIME);
    incrementServoRotation(ServoPos);
    //Init return array
    double *stats = (double*)malloc(2);
    //Get Lidar
    stats[0] = lidarGetRange();
    stats[1] = (ServoPos - 1);
    return stats;
}

 