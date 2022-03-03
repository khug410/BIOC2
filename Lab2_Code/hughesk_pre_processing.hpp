/* Name: Kelsey Hughes
   Date: 2/18/22
   Details: This is a header file that will call declaration of the namespace and class.
   The function will calculate the log intensity of normalized data
*/

#ifndef preprocess
#define preprocess

#include <math.h>
#include <vector> 
#include <iostream>
#include <fstream>

namespace BigKelsProcess{
    class processes{
        public:

        void preProcess(float logRatio);

        //This function will calculate the log intensity ratio of normalized data array.
        // It writes this ration to a specified file
        // @param data: a data array of the data that we want to calculate the log intensity of
        // @param size: size of the vector
        // @param data1: a vector of the non-sporulating data
        // @param logRatio: new vector with the log ratio
        // @return: the log intensity ratio to the file specified in the input argument

        void log(std::vector<float>* data, int size, std::vector<float>* data2, std::vector<float>* logRatio);

        private:
            float logRatio;
    };
}

#endif