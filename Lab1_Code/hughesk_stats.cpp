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

//call and calculate the histogram function
std::vector<float> BigKels::Stattys::getHist(std::vector<float>* data, int size, float average, float STD){

    //create a vector for the histogram that will hold the data
    std::vector<float> Total;
    float points = 10; 

    // calculation based on lab sheet
    double width = 0.4 * STD;

    double max = 0;
    double min = 0;

    // min and max based on lab handout
    max = average + (STD *3);
    min = average - (STD *3);

    // https://stackoverflow.com/questions/19252172/c-vector-trying-to-create-histogram

    // initializing Total vector
    for(int k=0; k<8; k++){
        Total.push_back(0);
    }

    for(int i=0; i<size;i++){

        if(((*data)[i]>min) && ((*data)[i] < (width + min))){
            Total[0]++;
        }
        // add one from first width value to second
        else if(((*data)[i] >= ((width*1) + min)) && ((*data)[i] < ((width*2) +min))){
            Total[1]++;
        }
        // add one from second width to third
        else if(((*data)[i] >= ((width*2) + min)) && ((*data)[i] < ((width*3) +min))){
            Total[2]++;
        }  
        // ++ from third width value to fourth
        else if(((*data)[i] >= ((width*3) + min)) && ((*data)[i] < ((width*4) +min))){
            Total[3]++;
        }  
        // add one from fourth to fifth range
        else if(((*data)[i] >= ((width*4) + min)) && ((*data)[i] < ((width*5) +min))){
            Total[4]++;
        } 

        // adds one between fifth and sixth range
        else if(((*data)[i] >= ((width*5) + min)) && ((*data)[i] < ((width*6) +min))){
            Total[5]++;
        }  

        // add between sixth and 7th 
        else if(((*data)[i] >= ((width*6) + min)) && ((*data)[i] < ((width*7) +min))){
            Total[6]++;
        }   

        // add between 7 and 8 
        else if(((*data)[i] >= ((width*7) + min)) && ((*data)[i] < ((width*8) +min))){
            Total[7]++;
        }  

        // anything between 8 and max
        else if(((*data)[i] >= ((width*8) + min)) && ((*data)[i] < max)){
            Total[8]++;
        }     
    }  


    // set values for vector to be easier to deal with
    // dividing by 10 so each = means 10 data points
    for(int d =0; d<8; d++){
        Total[d] = Total[d]/points;

    } 

    return Total;
}