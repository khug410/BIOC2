/*
Author: Kelsey Hughes
Date Created: 2/1/2022
Program: This header file will define functions that estimate statistics about a set of data including mean, standard deviation, and a histogram
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace BigKels{
    class Stattys{
        public:

        void stats(float min, float max, float mean, float STD);

        /* This function will calculate the minimum of an input array 
        @ param data: a vector of data to find min value
        @ param n: total vector size
        @ returns: The minimum value of the vector
        */
        
        float getMin(std::vector<float>* data, int n);

        /* This function will calculate the maximum of an input array 
        @ param data: a vector of data to find the maximum of
        @ param n: total vector size
        @ returns: The maximum value of the vector
        */
        float getMax(std::vector<float>* data, int n);

        /* This function will calculate the mean of input arrays
        @ param data: a vector of data to find the mean of
        @ param n: total vector size
        @ returns: the mean value of the vector
        */
        float getMean(std::vector<float>* data, int n);

        /* This function will calculate the standard deviation of input arrays
        @ param data: a vector of data to find the standard deviation of
        @ param n: total vector size
        @ param mean: mean value that come from the getMean() function
        @ returns: The standard deviation of the vector
        */
       
        float getSD(std::vector<float>* data, int n, float mean);

        /* This function will estimate a histogram from input arguments
        @ param data:a vector of data to find histogram of
        @ param n: total vector size
        @ param mean: mean value that comes from the getMean() function
        @ param STD: standard deviation value that comes from the the getSD() function
        @ returns: An array corresponding to quantity of data within each bin
        */

        float getHist(std::vector<float>* data, int n, float mean, float STD);

        private:

            float min;
            float max;
            float mean;
            float STD;

    
        };
}