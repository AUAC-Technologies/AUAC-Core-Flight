#include"PropThrustControl.h"

double *currentMotorValues = (double*)malloc(4);

PropThrustControl::PropThrustControl(){
	pinMode(BPIN1,OUTPUT);
    pinMode(BPIN2,OUTPUT);
    pinMode(BPIN3,OUTPUT);
    pinMode(BPIN4,OUTPUT);
}
			
uint8_t PropThrustControl::PWM_init(uint8_t MOTOR,double M_VEL) {
 	switch(MOTOR){
		case 1:
			thrustWriteFL(M_VEL);
			break;
		case 2:
			thrustWriteFR(M_VEL);
			break;
		case 3:
			thrustWriteBL(M_VEL);
			break;
		case 4:
			thrustWriteBR(M_VEL);
			break;		
	 }
	return;
}	 


uint8_t PropThrustControl::thrustWriteFL(double PWM){
	analogWrite(BPIN1,PWM);		//CLOCKWISE
	updateThrustValues(1,PWM);
	return;
}

uint8_t PropThrustControl::thrustWriteFR(double PWM){
	analogWrite(BPIN2,PWM);    //ANTI-CLOCKWISE
	updateThrustValues(2,PWM);
	return;
}

uint8_t PropThrustControl::thrustWriteBL(double PWM){
	analogWrite(BPIN3,PWM);    //ANTICLOCKWISE
	updateThrustValues(3,PWM);
	return;
}

uint8_t PropThrustControl::thrustWriteBR(double PWM){
	analogWrite(BPIN4,PWM);    //CLOCKWISE
	updateThrustValues(4,PWM);
	return;
}

uint8_t PropThrustControl::updateThrustValues(uint8_t MOTOR, double tLevel){
	currentMotorValues[MOTOR - 1] = tLevel;
	return;
}

double *PropThrustControl::returnCurrentThrustValues(){
	return currentMotorValues;
}