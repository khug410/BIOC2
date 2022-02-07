/*Name: Kelsey Hughes
Date: 2/6/22
Details: This is a header file for a program that will estimate the correlation coefficient between two data sets
*/

#include <math.h>
#include <fstream>
#include <vector>
#include <iostream>

namespace BigKelsCorr{
    class correlation{
        //this function will calculate the correlation coefficient between two data sets
        //@param data1: vector of data set one
        //@param data2:vector of data set two
        //@param n:size of the vectors
        //@return: the correlation coefficient between the two data sets
        float corcof(std::vector<float>* data1, std::vector<float>* data2, int n);

        private:
    };
}