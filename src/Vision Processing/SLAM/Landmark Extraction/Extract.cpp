#include"Extract.h"

double EXTRACTION::SAR_to_angle(double SAR){

}

/*double *EXTRACTION::dataPush(){
    LIDAR_LITE push;
    double *LIDAR_DATA = (double*)malloc(2);
    double *recv = push.GET_L_VALUE();
    LIDAR_DATA[0] = recv[0];
    LIDAR_DATA[1] = recv[1];
    return LIDAR_DATA;
}*/

double *EXTRACTION::updateMap(double **map){
    double *data = dataPush();
    double key = data[1];
    double value = data[0];
    uint8_t SOA; //Sum of angle
    //Linear Search map for angle key
    for(size_t i = 0;i < SOA;i += 2){
        //if key is found update lidar value
        if(*map[i] == key){
            *map[i + 1] = value;
            break;
        }
    }
    return;
}