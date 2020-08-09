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

#ifndef NAV
#define NAV

#include<stddef.h>
#include<stdint.h>
#include<math.h>
#include"../utility/utiltiyFunctions.h"
#include"../Control/Thrust/MotorMixing/MMA.h"
#include"../Control/Feedback Controllers/PositionController/PositionController.h"

class BEARING {
    private:
        uint8_t GET_REMOTE_COORDINATE();

        double COMPUTE_BEARING(double current_lat,double current_long,double final_lat,double final_long);

        double DISTANCE_BETWEEN(double current_lat,double current_long,double final_lat,double final_long);

    public:
        //Function returns the remote position to the flight feedback controller
        double *RETURN_ANCHOR_POSITION();

};

#endif