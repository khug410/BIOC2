/* Gabbie Rohde
   Lab 1 Stats file - calculates mean, min, max, standard dev, number of 
   data points, and prints out histogram of data files in ./EEG_DATA
   Due Feb 15 2022
*/  

#include "RohdeG_stats.hpp"

using namespace GabeTheBabe; 

float GabeTheBabe::StatsBro::meanValue(std::vector<float>* data, int size){

    float sum = 0, average = 0; 
    int i =0;

    for(i=0; i<size; i++){
        sum = sum + (*data)[i]; 
    }
    average = sum / size; 
    return average;

}
float GabeTheBabe::StatsBro::standardDev(std::vector<float>* data, int size, float average){

    float stddev = 0, sum = 0, calculations = 0;
    int i = 0; 

    for(i=0; i < size; i++){
        calculations = pow((((float)((* data)[i])) - average),2);
        sum = sum + calculations;
    }
    float new_avg = sum / (float)size; 

    stddev = sqrt(new_avg);
    return stddev;

}

float GabeTheBabe::StatsBro::minVal(std::vector<float>* data, int size){
    
    int i = 0; 
    float min = (float)(* data)[0]; 

    for(i = 0; i< size; i++){
        if(((float)((* data)[i])) < min){
            min = ((float)((* data)[i]));
        }
    }
    return min;
}
float GabeTheBabe::StatsBro::maxValue(std::vector<float>* data, int size){
    int i = 0;
    float max = (float)(* data)[0]; 

    for(i=0; i<size; i++){
        if((float)(* data)[i]> max){
            max = (float)((* data)[i]); 
        }
    }
    return max; 
}

void GabeTheBabe::StatsBro::allStats(float avg, float stddev, float min, float max){

    this->avg = avg;
    this->stddev = stddev;
    this->min = min;
    this->max = max; 

}

std::vector<float> GabeTheBabe::StatsBro::getHist(std::vector<float>* data, int size, float avg, float stddev){

    // https://www.cplusplus.com/reference/vector/vector/
    std::vector<float> totalBins;
    float points = 10; 

    // in lab handout sheet 
    double bin_width = 0.4 * stddev;

    // larger and smaller ranges for bins
    double end_bin = avg + (stddev *3);
    double first_bin = avg - (stddev *3);

    // https://stackoverflow.com/questions/19252172/c-vector-trying-to-create-histogram

    // initializing totalBins vector
    for(int i=0; i<9; i++){
        totalBins.push_back(0);
    }

    // worked with Kelsey and Cassie about logic with how to break this stuff up 
    /* Logic for each of them: 
            for each datapoint at whatever 'i' value from variable data, it checks if the value is within the range.
            range is based on standard deviation and average values. these are seen in the calculations for first_bin and end_bin
            and if the values are in the range specified then add one to vector totalBins with whatever bin value is specified. 
            totalBins vector data is then returned 
    */ 
    for(int i=0; i<size;i++){

        if(((*data)[i]>first_bin) && ((*data)[i] < (bin_width + first_bin))){
            totalBins[0]++;
        }

        else if(((*data)[i] >= ((bin_width*1) + first_bin)) && ((*data)[i] < ((bin_width*2) + first_bin))){
            totalBins[1]++;
        }

        else if(((*data)[i] >= ((bin_width*2) + first_bin)) && ((*data)[i] < ((bin_width*3) + first_bin))){
            totalBins[2]++;
        }  

        else if(((*data)[i] >= ((bin_width*3) + first_bin)) && ((*data)[i] < ((bin_width*4) + first_bin))){
            totalBins[3]++;
        }  

        else if(((*data)[i] >= ((bin_width*4) + first_bin)) && ((*data)[i] < ((bin_width*5) + first_bin))){
            totalBins[4]++;
        } 

        else if(((*data)[i] >= ((bin_width*5) + first_bin)) && ((*data)[i] < ((bin_width*6) + first_bin))){
            totalBins[5]++;
        }  

        else if(((*data)[i] >= ((bin_width*6) + first_bin)) && ((*data)[i] < ((bin_width*7) + first_bin))){
            totalBins[6]++;
        }   

        else if(((*data)[i] >= ((bin_width*7) + first_bin)) && ((*data)[i] < ((bin_width*8) + first_bin))){
            totalBins[7]++;
        }  

        else if(((*data)[i] >= ((bin_width*8) + first_bin)) && ((*data)[i] < end_bin)){
            totalBins[8]++;
        }     
    }  

    // dividing by 10 so each = means 10 data points
    for(int i = 0; i<9; i++){
        totalBins[i] = totalBins[i]/10;
    } 
    return totalBins;
} 
