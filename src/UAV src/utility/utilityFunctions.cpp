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

#include"utiltiyFunctions.h"

//This function converts decimal degrees to radians
AUAC_BASE_DOUBLE UTILITY_FUNCTIONS::deg2rad(double deg){
	return (deg * pi / 180);
}
//This function converts radians to decimal degrees
AUAC_BASE_DOUBLE UTILITY_FUNCTIONS::rad2deg(double rad){
	return (rad * 180 / pi);
}

//This function generates a 5 digit Alphanumeric random string
AUAC_BASE_STRING UTILITY_FUNCTIONS::generateAlphanumericString(){
	AUAC_BASE_STRING alphabet = "abcdefghijklmnopqrstuvwxyz";
	AUAC_BASE_8 randAnchor = random(0,1);
	AUAC_BASE_8 randNumber = random(0,27);
	AUAC_BASE_STRING final_string;
	for(size_t i = 0; i < 10;i++){
		if(random(0,1) == 0){
			//Add String
			//AUAC_BASE_STRING append = alphabet[randNumber];
			//strcat(final_string,);
		}else{
			//Add int

		}
	}

}
        