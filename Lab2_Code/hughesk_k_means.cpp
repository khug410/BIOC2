#include "hughesk_k_means.hpp"
#include "hughesk_stats.hpp" 

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <fstream>

void BigKelsCluster::Cluster::setName(std::string objName){
    this->objName = objName;
}

std::string BigKelsCluster::Cluster::getName(){
    return this->objName;
}

void BigKelsCluster::Cluster::setMean(float objMean){
    this->objMean = objMean;
}

float BigKelsCluster::Cluster::getMean(){
    return this->objMean;
}

void BigKelsCluster::Cluster::setData(std::vector<float> data){
    this->data = data;
}

std::vector<float> BigKelsCluster::Cluster::getData(){
    return this->data;
}

float BigKelsCluster::Cluster::dist(float datapoint){
    // calculated |a-b|
    float distance = 0;
    distance = abs((this->objMean) - datapoint);
    return distance;
}

int main(int argc, char* argv[]){

    //instantiate necessary variables
    BigKelsCluster::Cluster clustDist;
    BigKels::Stattys statsDat;

    //instaniate the necessary names of the clustes
    BigKelsCluster::Cluster supp;
    BigKelsCluster::Cluster stat;
    BigKelsCluster::Cluster expr;

    //read in the data file named log_ratio_input.dat
    std::string inputFile = argv[1];
    std::string geneData = argv[2];

    //get the input streams
    std::ifstream logStream("log_ratio_input.dat");
    std::ifstream genesStream("gene_list.txt");


    std::string dataOne; //temp variable to hold data
    std::vector<float> logRatio; //store file data in here
    //open both the data files
    int fileOneSize =0;
    if(logStream.is_open()){
        while(std::getline(logStream, dataOne)){
            logRatio.push_back(stof(dataOne));
            fileOneSize++;
        }
    }
    else{
        std::cout << "LogFile (File 1) does not exist" << "\n";
        return 0;
    }

    //read in data file 2 (gene file)

    std::string dataTwo; //temp variable to hold data
    std::vector<float> geneData; //store file data in here
    //open both the data files
    int fileTwoSize=0;
    if(logStream.is_open()){
        while(std::getline(genesStream, dataTwo)){
            geneData.push_back(stof(dataTwo));
            fileTwoSize++;
        }
    }
    else{
        std::cout << "geneFile (File 2) does not exist" << "\n";
        return 0;
    }

    //initialize three cluster classes, their names, and their means
    std::vector<float> suppressedData;
    int suppressed = 0;
    float suppressedGenes;
    //set the initiail mean of the suppressed gene
    float meanSuppressed = -0.5;

    std::vector<float> stationaryData;
    int stationary =0;
    float stationaryGenes;
    //set the initial mean of stationary
    float meanStationary = 0;

    std::vector<float> expressedData;
    int expressed=0;
    float expressedGenes;
    //set the initial mean of expressed
    float meanExpressed = 0.5;

    //set the names of the clusters
    supp.setName("SuppressedGene");
    stat.setName("StationaryGene");
    expr.setName("Expressed Gene");

    //set the means of the clusters
    supp.setMean(meanSuppressed);
    stat.setMean(meanStationary);
    expr.setMean(meanExpressed);



}
