#include"PropThrustControl.h"

double *currentMotorValues = (double*)malloc(4);

PropThrustControl::PropThrustControl(){
	pinMode(BPIN1,OUTPUT);
    pinMode(BPIN2,OUTPUT);
    pinMode(BPIN3,OUTPUT);
    pinMode(BPIN4,OUTPUT);
}
			
uint8_t PropThrustControl::PWM_init(uint8_t MOTOR,uint8_t M_VEL) {
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


uint8_t PropThrustControl::thrustWriteFL(uint8_t PWM){
	analogWrite(BPIN1,PWM);		//CLOCKWISE
	return;
}

uint8_t PropThrustControl::thrustWriteFR(uint8_t PWM){
	analogWrite(BPIN2,PWM);    //ANTI-CLOCKWISE
	return;
}

uint8_t PropThrustControl::thrustWriteBL(uint8_t PWM){
	analogWrite(BPIN3,PWM);    //ANTICLOCKWISE
	return;
}

uint8_t PropThrustControl::thrustWriteBR(uint8_t PWM){
	analogWrite(BPIN4,PWM);    //CLOCKWISE
	return;
}

uint8_t PropThrustControl::updateThrustValues(uint8_t MOTOR, double tLevel){
	currentMotorValues[MOTOR - 1] = tLevel;
	return;
}

double *PropThrustControl::returnCurrentThrustValues(){
	return currentMotorValues;
}