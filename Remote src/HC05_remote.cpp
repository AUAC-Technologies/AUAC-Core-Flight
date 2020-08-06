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

#include"HC05_remote.h"

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
