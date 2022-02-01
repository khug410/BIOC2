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

namespace BigKels{
    class Stattys{
        public:

        /* This function will calculate the minimum of an input array 
        @ param
        @ returns: The minimum value
        */
        void calcMin(float array[]){
  
        }
        float getMin();

        /* This function will calculate the maximum of an input array 
        @ param
        @ returns: The maximum value
        */
        void calcMax(float array[]){
        }
        float getMax();

        /* This function will calculate the mean of input arrays
        @ param
        @ returns: the mean
        */
        void calcMean(float array[]){
        }
        float getMean();

        /* This function will calculate the standard deviation of input arrays
        @ param
        @ returns: The standard deviation
        */
        void calcSD(float array[]){
        }
        float getSD();

        /* This function will estimate a histogram from input arguments
        @ param
        @ returns: An array corresponding to quantity of data within each bin
        */
        void histogram(float array[]){
        }
        float getHist();

        private:

    
        };
}