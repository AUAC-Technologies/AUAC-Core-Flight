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

#include"BMP085.h"

AUAC_BASE_DOUBLE Pressure::getTemperature(){
    return Psensor -> readTemperature();
}

AUAC_BASE_DOUBLE Pressure::getSLPressure(){
    return Psensor -> readSealevelPressure();
}

AUAC_BASE_DOUBLE Pressure::getPressure(){
    return Psensor -> readPressure();
}

AUAC_BASE_DOUBLE Pressure::getAltitude(){
    double temp1, temp2, height;
	//Calculating Altitude from pressure using hypsometric formula
	temp1 = (pow((getPressure() / getSLPressure()), (1 / 5.257)) - 1);
	temp2 = temp1 * (getTemperature() + 273.15);
	height = temp2 / 0.0065;
    return height;
}