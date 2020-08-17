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

#include"SD_API.h"

AUAC_BASE_STRING *fileRegistry = (AUAC_BASE_STRING *)malloc(20);
AUAC_UBASE_8 index; 

//Function to add file to available file registry
NO_RETURN SD_API::registerFile(AUAC_BASE_STRING filename){
    fileRegistry[index] = filename;
    index++;
}

//Function to create a file
AUAC_BASE_STRING SD_API::createFile(){
    //Generate fileName
    //Utility object for alphanumeric generator function
    UTILITY_FUNCTIONS *util = new UTILITY_FUNCTIONS();
    //Alphanumeric text
    AUAC_BASE_STRING fName = util -> generateAlphanumericString();
    //Create File 
    File tempCreate;
    tempCreate = SD.open(fName,FILE_WRITE);
    tempCreate.close();
    //Register File Name
    registerFile(fName);
    //Free 
    delete util;
    return fName;
}

//Function to delete a file
NO_RETURN SD_API::deleteFile(AUAC_BASE_STRING file){
    SD.remove(file);
}

AUAC_BASE_STRING SD_API::getFileDir(){

}

//Function to add data to specified File
AUAC_BASE_32 SD_API::addDataToFile(AUAC_BASE_STRING file){

}

AUAC_BASE_STRING SD_API::readFileintoBuffer(AUAC_BASE_STRING file){
    File temp;
    //temp.open(file);
    AUAC_BASE_STRING buffer;
    if(temp){
        while(temp.available()){
            //buffer = temp.read();
        }
    }
    return buffer;
}       