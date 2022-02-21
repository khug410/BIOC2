#include "hughesk_pre_processing.hpp"
#include "hughesk_vector_ops.hpp"
#include "hughesk_stats.hpp"

#include <math.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <string>

void BigKelsProcess::processes::preProcess(float logRatio){
    this -> logRatio = logRatio;
}

void BigKelsProcess::processes::log(std::vector<float>* data, int size, std::vector<float>* data2, std::vector<float>* logRatio){
    int sp = 0; //sporulating
    int nsp = 0; //non-sporulating

    for (int sp=0; sp<size; sp++){
        logRatio -> push_back(0);
    }

    for (int nsp = 0; nsp<size; nsp ++){
        logRatio ->at(nsp) = log10(((*data)[nsp]/(*data2)[nsp]));
    }
}

int main(int argc, char* argv[]){
    
    //call the vector and statistics functions
    Vecties::vectiesFunctions vectorData;
    BigKels::Stattys stattyData;
    BigKelsProcess::processes processingData;

    //read in six command line arguments
    //file information
    std::string f1; //red on
    std::string f2; //red back
    std::string f3; //green on
    std::string f4; //green back
    //std::string f5; //output file
    //std::string f6; //number of genes

    //temp vatriables to hold data file
    std::string d1;
    std::string d2;
    std::string d3;
    std::string d4;
    //std::string d5;
    //std::string d6;

    //assigning files to the correct arguments
    f1 = argv[1];
    f2 = argv[2];
    f3 = argv[3];
    f4 = argv[4];
    //f5 = argv[5];
    //f6 = argv[6];

    //data points variables 
    int dataPoint1 = 0;
    int dataPoint2 =0;
    int dataPoint3 =0;
    int dataPoint4 =0;

    //hold the array data
    std::vector<float> array1;
    std::vector<float> array2;
    std::vector<float> array3;
    std::vector<float> array4;
    //std::vector<float> array5;
    //std::vector<float> array6;

    //
    std::ifstream ls1;
    std::ifstream ls2;
    std::ifstream ls3;
    std::ifstream ls4;
    //std::ifstream ls5;


    //open each file
    ls1.open(f1);
    ls2.open(f2);
    ls3.open(f3);
    ls4.open(f4);
    //ls5.open(f5);

    long arg = strtol(argv[6], NULL, 10);
	int genes = arg; 

    if(argc > 8) {
		std::cout << "Incorrect arguments. Exiting program.\n";
		return 0; 
	}

    //for each data file check that it exists before reading it 
    if(ls1.is_open()){
        while(std::getline(ls1,d1)){
            array1.push_back(stof(d1));
            dataPoint1++;
        }
    }
    else{
        std::cout << "Data file 1 cannot be found." << "\n";
        return 0;
    }

    std::cout << "data point1: " << dataPoint1 << "\n";
    if(ls2.is_open()){
        while(std::getline(ls2,d2)){
            array2.push_back(stof(d2));
            dataPoint2++;
        }
    }
    else{
        std::cout << "Data file 2 cannot be found." << "\n";
        return 0;
    }
    std::cout << "data point2: " << dataPoint2 << "\n";

    if(ls3.is_open()){
        while(std::getline(ls3,d3)){
            array3.push_back(stof(d3));
            dataPoint3++;
        }
    }
    else{
        std::cout << "Data file 3 cannot be found." << "\n";
        return 0;
    }
    std::cout << "data point3: " << dataPoint3 << "\n";

    if(ls4.is_open()){
        while(std::getline(ls4,d4)){
            array4.push_back(stof(d4));
            dataPoint4++;
        }
    }
    else{
        std::cout << "Data file 4 cannot be found." << "\n";
        return 0;
    }

    std::cout << "data point4: " << dataPoint4 << "\n";
    //check that the number of genes requested 
    int num = 6188;
    if(genes > num){
        std::cout << "The number of genes requested is too large for the number of data points";
        return 0;
    }


  
    //subtract the corresponding background intensities from the red and green datasets
    std::vector<float> sub1;
    std::vector<float> sub2;

    float redData = 0;
    float greenData =0;

    //check that both data points are equal
    if(dataPoint1 == dataPoint2){
        redData = dataPoint1;
        
    }
    std::cout << "red data : " << redData << "\n";

    if(dataPoint3 == dataPoint4){
        greenData = dataPoint3;
    }

    //red - subred
    sub1 = vectorData.subtraction(&array1, redData, &array2);
    
    //green - subgreen
    sub2 = vectorData.subtraction(&array3, greenData, &array4);

    //calculate the means of the corrected red and green datasets
    float meanRed = 0;
    float meanGreen = 0;

    std::vector<float> greenNorm;
    std::vector<float> redNorm;

    meanRed = stattyData.getMean(&array1, redData);
    meanGreen = stattyData.getMean(&array3, greenData);


    //normalize the corrected green  and red data by the green dataset mean
    redNorm = vectorData.division(&sub1,redData,meanRed);
    greenNorm = vectorData.division(&sub2, greenData, meanGreen);

    std::vector<float> logRatio;
    std::cout << "Red Data : " << redData << "\n";
    //calculate the log intensity 
    if(num = redData){
        processingData.log(&redNorm, redData,&greenNorm,&logRatio);

    }

    
    //create a file to write the log ratio to
    std::string outfile(argv[5]);
    std::ofstream outFile5;
    outFile5.open(outfile);

    float dat = 0;
/*
    //for testing purposes
    for(int counter=0; counter<6118; counter++){
        std::cout << "Log Ratio : " << logRatio[counter] << "\n";
    }
   */ 
    if(outFile5.is_open()){
        //putting log ratio
        for(int count=0;count<redData;count++){
            dat = logRatio[count];
           // std::cout << dat;
            outFile5 << dat;
            outFile5 << "\n";

        }
    }

    else{
        std::cout<< "Log Ratio file is not there";
        return 0;
    } 
    
    //close the file
    outFile5.close();
/*
    //also print the values to the screen
    for(int counter=0; counter<6118; counter++){
        std::cout << "Log Ratio : " << logRatio[counter] << "\n";
    }
    */
    return 0;
}

 



