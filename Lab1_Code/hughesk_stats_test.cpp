/*
Author: Kelsey Hughes
Date Created: 2/1/2022
Program: This file will define functions that estimate statistics about a set of data including mean, standard deviation, and a histogram
*/

#include "hughesk_stats.hpp"
#include "hughesk_stats.cpp"

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <fstream>



//main function
int main(int argc, char* argv[]){
    
    std::vector<float> data;
    //create a variable to hold the info
    BigKels::Stattys info;


    //create variable to hold histogram data
    std::vector<float> dataH;
    std::string file;
    std::string data1;

    //declare variables
    float min;
    float max;
    float mean;
    float STD;
    int n = 0;
    int i = 0;
    float dataH1;

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
    STD = info.getSD(&data, n, mean);

    //print info for mean, max, min, and standard deviation
    std::cout << "Min value is: " << min << "\n";
    std::cout << "Max value is: " << max << "\n";
    std::cout << "Mean value is: " << mean << "\n";
    std::cout << "Standard Deviation value is: " << STD << "\n";

    std::cout << "Histogram: \n";

    dataH = info.getHist(&data, n, mean, STD);
    int l;
int temp = 0;

    for(l=0; l<8; l++){
        std::cout<< '|';

        for(int j=0; j<dataH[l]; j++){
            std::cout<< '=';
            temp++;
        }
        std::cout<<'\n';
    }
    //total bins
    std::cout<< "10 data points \n";

    printf("temp: %d", temp);
}





