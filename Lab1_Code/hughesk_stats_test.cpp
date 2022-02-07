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

/*
//main function
int main(int argc, char* argv[]){
    
    std::vector<float> data;
    //create a variable to hold the info
    BigKels::Stattys info;

    std::string file;
    std::string data1;

    //declare variables
    float min;
    float max;
    float mean;
    float STD;
    int n = 0;
    int i = 0;

    //ensure there is only one input argument corresponding to the path of the input data file
    if(argc > 2){
        std::cout <<"Incorrect Number of Arguments. Exiting Program. \n";
        return 0; //error
    }


    file = argv[1]; //prompted to enter file name
    std::ifstream list;
    list.open(file);

    //read the file -- count the number of data point
    if(list.is_open()){
        
        while(std::getline(list, data1)){
            data.push_back(stof(data1));
            n++; //prints the number of data pointa
        }
    }
    else{
        std::cout<<"File cannot be found" << "\n";
    }

    //write the number of data points
    std::cout << "# of Data Points: " << n << "\n";

    //call the min, max, mean, and std functions
    min = info.getMin(&data, n);
    max = info.getMax(&data, n);
    mean = info.getMean(&data, n);
    STD = info.getSD(&data,n,mean);

    //print info for mean, max, min, and standard deviation
    std::cout << "Min value is: " << min << "\n";
    std::cout << "Max value is: " << max << "\n";
    std::cout << "Mean value is: " << mean << "\n";
    std::cout << "Standard Deviation value is: " << STD << "\n";
    
}*/




