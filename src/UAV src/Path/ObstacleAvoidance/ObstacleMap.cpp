#include"ObstacleMap.h"

double OBSTACLE_MAP::GET_ATLTITUDE(){
    GPS *rec = new GPS;
    double alt = rec -> getapproxAltitude();
    delete rec;
    return alt;
}

//ROLL = 0 PITCH = 1 YAW = 2
double *OBSTACLE_MAP::GET_DOF(){
    IMU *val = new IMU;
    double *dof = (double*)malloc(3);
    dof[0] = val -> getRollAxis();
    dof[1] = val -> getPitchAxis();
    dof[2] = val -> getYawAxis();
    delete val;
    return dof;
}

double OBSTACLE_MAP::AVT_STATISTICAL_FILTERING(double *set){
    //AVT algorithm
    uint8_t size = sizeof(set)/sizeof(set[0]);
    //Calculate the standard deviation and average value
    double StandardDeviation = STANDARD_DEVIATION(set);
    double AVG = AVERAGE_FILTER(set);
    double *dropData = (double*)malloc(1);
    uint8_t dropDataIndex = 0;
    //Drop any data that is greater or less than average ± one standard deviation
    for(size_t i = 0; i < size;i++){
        if(set[i] < (AVG - StandardDeviation) || set[i] > (AVG + StandardDeviation)){
            continue;
        }else{
            dropData[dropDataIndex] = set[i];
            dropDataIndex++;
            realloc(dropData,dropDataIndex + 1);
        }
    }
    //Calculate average value of remaining data and present result as actual value representing data sample
    double finAvg = AVERAGE_FILTER(dropData);
    free(dropData);
    return finAvg;
}

double OBSTACLE_MAP::STANDARD_DEVIATION(double *array){
    uint8_t size = sizeof(array)/sizeof(array[0]);
    //Work out the AVG
    double mean = AVERAGE_FILTER(array);
    double *temp = (double*)malloc(size);
    //for each number, subtract the Mean and square the result
    for(size_t i = 0; i < size;i++){
        temp[i] = pow((array[i] - mean),2);
    }
    //work out the mean of those squared differences.
    double finalMean = AVERAGE_FILTER(temp);
    free(temp);
    //Take the square root and return
    return sqrt(finalMean);
}

double OBSTACLE_MAP::AVERAGE_FILTER(double *array){
    //Average Function
    double avg,sum;
    uint8_t size = sizeof(array)/sizeof(array[0]);
    for(size_t i = 0; i < size;i++){
        sum += array[i];
    }
    return avg = sum / size; 
}

//Function to find a lat lon point, when bearing, distance and another lat lon is given
double *OBSTACLE_MAP::DETERMINE_LATLONG_FROM_DIST(double initiallatitude, double initiallongitude,
                                                                    double bearing, double metres){
    double newCOORD[2];
	//Latitude
	double earth_radius = 6378.137;							 //radius of the earth in kilometer
	//latitude of second point = la2 =  asin(sin la1 * cos Ad  + cos la1 * sin Ad * cos θ), 
	double m = sin(initiallatitude) * cos(metres / earth_radius) + cos(initiallatitude) * sin(metres / earth_radius) * cos(bearing);
	double new_latitude = asin(m);
	newCOORD[0] = new_latitude;
	//Longitude of second point = lo2 = lo1 + atan2(sin θ * sin Ad * cos la1 , cos Ad – sin la1 * sin la2)
	double temp = atan2(sin(bearing) * sin(metres / earth_radius) * cos(initiallatitude), cos(metres / earth_radius) - sin(initiallatitude) * sin(new_latitude));
	double new_longitude = initiallongitude + temp;
	newCOORD[1] = new_longitude;
	return newCOORD;
}

double OBSTACLE_MAP::TRIANGULATE_MEASURED_VALUE_ALTITUDE(double bearing,double reading){
    
}

double OBSTACLE_MAP::TRIANGULATE_MEASURED_VALUE_WORLD_BEARING(double bearing,double reading){

}