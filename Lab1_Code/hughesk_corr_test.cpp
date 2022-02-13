#include "hughesk_corr.hpp"
#include "hughesk_stats.hpp"
//#include "hughesk_corr.cpp"
//#include "hughesk_stats.cpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){

    BigKelsCorr::correlationFunctions dataCorrelation; //create variable for data

    //create two variables for the two vectors of data from fiels
    std::vector<float> fileData1;
    std::vector<float> fileData2;

    //create two strings
    std::string Data1;
    std::string Data2;

    //create two file input arguments
    std::string FileA;
    std::string FileB;

    //varaibles
    float corr = 0;
    int i1 =0;
    int i2 =0;
    int i =0;

    //ensure the program takes in two arguments
    if(argc < 3){
        std::cout << "Need more arguments. \n";
        return 0;
    }

    //read in both files and count number of data points
    FileA = argv[1];
    std::ifstream list;
    list.open(FileA);

    //count number in file as done before
    if(list.is_open()){
        while(std::getline(list, Data1)){
            fileData1.push_back(stof(Data1));
            i1++;
        }
    }
    else{
        //error
        std::cout << "Data file not found" << "\n";
        return 0;
    }

    //read in second file
    FileB = argv[2];
    std::ifstream list2;
    list2.open(FileB);

    //count number in file as done before
    if(list2.is_open()){
        while(std::getline(list2, Data2)){
            fileData2.push_back(stof(Data2));
            i2++;
        }
    }
    else{
        //error
        std::cout << "Data file not found" << "\n";
        return 0;
    }

    //ensure data files are the same size
    if(i1 == i2){
        i= i1;
    }
    else{
        std::cout << "Error because data files must be the same size" << "\n";
        return 0;
    }

    //call the function for correlation coeeficient
    corr = dataCorrelation.corrcof(&fileData1, &fileData2, i);

    //print out correlation coefficient
    std::cout << corr << "\n";

}

