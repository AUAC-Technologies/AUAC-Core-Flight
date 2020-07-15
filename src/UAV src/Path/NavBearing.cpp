#include"NavBearing.h"

uint8_t BEARING::GET_REMOTE_COORDINATE(){

}

double BEARING::COMPUTE_BEARING(double current_lat,double current_long,double final_lat,double final_long){
	UTILITY_FUNCTIONS *convert = new UTILITY_FUNCTIONS;
    double temp1,temp2,bearing;
	temp1 = sin(final_long - current_long) * cos(final_lat);
	temp2 = cos(current_lat) * sin(final_lat) -  sin(current_lat) * cos(final_lat) * cos(final_long - current_long);
	bearing = atan2(temp2, convert -> rad2deg(temp1));
	delete convert;
	return bearing;
}

double BEARING::DISTANCE_BETWEEN(double current_lat,double current_long,double final_lat,double final_long){
	UTILITY_FUNCTIONS *convert = new UTILITY_FUNCTIONS;
    double theta, dist;
	if ((current_lat == final_lat) && (current_long == final_long)){
		return 0;
	}
	else{
		theta = current_long - final_long;
		dist = sin(convert -> deg2rad(current_lat)) * sin(convert -> deg2rad(final_lat)) + cos(convert -> deg2rad(current_lat)) * cos(convert -> deg2rad(final_lat)) * cos(convert -> deg2rad(theta));
		dist = acos(dist);
		dist = convert -> rad2deg(dist);
		dist = dist * 60 * 1.1515;
		dist = dist * 1.609344;
		return (dist);
	}
}