#include"HC05.h"

SoftwareSerial BTSerial(2, 3); // RX | TX

HC05::HC05(){
    //Set to HC-05 default baud rate, found using AT+UART.  It is usually 38400.
    BTSerial.begin(38400);
}

String HC05::compressStrings(String x, String y){
    //Separate strings with '_'
    return (x + '_') + y;
}

String *HC05::decompressString(String x){
    String *newStr = (String*)malloc(2);
    String delimiter = "_";
    uint8_t pos = x.indexOf(delimiter);
    newStr[0] =  x.substring(0, pos);
    newStr[1] = x.substring(pos + 1,x.length());
    return newStr;
}
