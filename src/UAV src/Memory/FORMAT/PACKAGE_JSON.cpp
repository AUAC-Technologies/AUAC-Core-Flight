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

#include"PACKAGE_JSON.h"

//Function serializes JSON object and returns JSON doc in array
AUAC_BASE_STRING PACKAGE_JSON::serializeToJson(JSON_OBJECT object){
    //Return array
    AUAC_BASE_STRING serialized;
    //Serialize to JSON
    serializeJson(object,serialized,200);
    return serialized;
}

template<typename DEFINED>
DEFINED PACKAGE_JSON::deserializeJson(AUAC_BASE_STRING jsonDoc){
    //Create object
    StaticJsonDocument<200> temp;
    //Deserialize the JSON document
    DeserializationError error = deserializeJson(temp, json);
    //Test if parsing succeeds.
    if(error){
        //Handle error
    }
    
}

//Function adds data to JSON object 
template<typename DEFINED>
DEFINED PACKAGE_JSON::addToJsonObject(JSON_OBJECT object,AUAC_BASE_STRING dataCategory, DEFINED data){
    //Add data to JSON object
    x[dataCategory] = data;
    return data;
}