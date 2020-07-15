#include"utiltiyFunctions.h"

//This function converts decimal degrees to radians
double UTILITY_FUNCTIONS::deg2rad(double deg){
	return (deg * pi / 180);
}
//This function converts radians to decimal degrees
double UTILITY_FUNCTIONS::rad2deg(double rad){
	return (rad * 180 / pi);
}


        