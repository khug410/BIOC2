/*Name: Kelsey Hughes
Date: 2/6/22
Details: This is a header file for a program that will estimate the correlation coefficient between two data sets
*/

//#include "hughesk_corr.cpp"
#ifndef Kelsey1
#define Kelsey1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>


namespace BigKelsCorr{
    class correlationFunctions{
        public:
        //this function will calculate the correlation coefficient between two data sets
        //@param data1: vector of data set one
        //@param data2:vector of data set two
        //@param n:size of the vectors
        //@return: the correlation coefficient between the two data sets
        float corrcof(std::vector<float>* data1, std::vector<float>* data2, int n);

        private:
    };
}
#endif