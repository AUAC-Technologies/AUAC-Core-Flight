#include"BMP085.h"

double Pressure::getTemperature(){
    return Psensor.readTemperature();
}

double Pressure::getSLPressure(){
    return Psensor.readSealevelPressure();
}

double Pressure::getPressure(){
    return Psensor.readPressure();
}

double Pressure::getAltitude(){
    double temp1, temp2, height;
	//Calculating Altitude from pressure using hypsometric formula
	temp1 = (pow((getPressure() / getSLPressure()), (1 / 5.257)) - 1);
	temp2 = temp1 * (getTemperature() + 273.15);
	height = temp2 / 0.0065;
    return height;
}