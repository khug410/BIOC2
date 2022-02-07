/*
Author: Kelsey Hughes
Date Created: 2/1/2022
Program: This file will define functions that estimate statistics about a set of data including mean, standard deviation, and a histogram
*/

#include "hughesk_stats.hpp"

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <fstream>

//instantiate the necessary variables from the header file
void BigKels::Stattys::stats(float min, float max, float mean, float STD){
    this -> min = min;
    this -> max = max;
    this -> mean = mean;
    this -> STD = STD;
}

//call and calculate the getMin() function
float BigKels::Stattys::getMin(std::vector<float>* data, int n){
    int i = 0;
    float minimum = (*data)[i];

    for(i=0; i<n; i++){
        if((*data)[i] < minimum)
        minimum = (*data)[i];
    }

    return minimum;
}

//call and calculate the getMax() function
float BigKels::Stattys::getMax(std::vector<float>* data, int n){
    int i = 0;
    float maximum = (*data)[i];

    for(i=0; i<n; i++){
        if((*data)[i] > maximum)
        maximum = (*data)[i];
    }

    return maximum;
}

//call and calculate the getMean() function
float BigKels::Stattys::getMean(std::vector<float>* data, int n){
    float sum = 0;
    float average;
    float i;
    
    for(i=0; i<n; i++){
        sum = sum + (*data)[i]; 
    }

    average = sum/n;

    return average;
}

//call and calculate the getSD() function
float BigKels::Stattys::getSD(std::vector<float>* data, int n, float average){
    int i;
    float sum = 0;
    float mean = 0;
    float STD = 0;
    float info = 0;

    for(i=0;i<n;i++){
        info = pow(((*data)[i] - average), 2);
        sum = sum + info;   
    }

    //again find the mean 
    mean = sum/n;

    //sqrt
    STD = sqrt(mean);

    return STD;
}