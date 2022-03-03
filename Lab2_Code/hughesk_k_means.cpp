/* Name: Kelsey Hughes
   Date: 2/24/2022
   Details: This is the cpp file that will declare the logicfor the cluster class. 
   This will separate the data into three different clusters after going through the kmeans algorithm.
*/
#include "hughesk_k_means.hpp"
#include "hughesk_stats.hpp" 

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <fstream>
#include <string>

void BigKelsCluster::Cluster::setName(std::string objName){
    this->objName = objName;
}

std::string BigKelsCluster::Cluster::getName(){
    return this->objName;
}

void BigKelsCluster::Cluster::setMean(float objMean){
    this->objMean = objMean;
}

float BigKelsCluster::Cluster::get_Mean(){
    return this->objMean;
}

void BigKelsCluster::Cluster::setData(std::vector<float> data){
    this->data = data;
}

std::vector<float>* BigKelsCluster::Cluster::getData(){
    return &(this->data);
}
float BigKelsCluster::Cluster::getFinalData(int final){
    return this ->data[final];
}

float BigKelsCluster::Cluster::dist(float datapoint){
    // calculated |a-b|
    float distance = 0;
    distance = abs((this->objMean) - datapoint);
    return distance;
}

int main(int argc, char* argv[]){

    //instantiate necessary variables
    BigKels::Stattys statsDat;

    //instaniate the necessary names of the clusters
    BigKelsCluster::Cluster supp;
    BigKelsCluster::Cluster stat;
    BigKelsCluster::Cluster expr;

    //file one information
    std::string fileOne; //logratio.dat file
    std::string dataOne; //temp variable to hold data
    fileOne = argv[1];
    std::vector<float> logRatio; //store file data in here

    std::ifstream logStream;
    logStream.open(fileOne);
    //open both the data files
    int fileOneSize =0;
    float num;


    //error checking for incorrect number of arguments 
    if(argc > 2) {
		std::cout << "Incorrect number of arguments. Exiting program.\n";
		return 0; 
	}


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
    std::ifstream geneStream ("gene_list.txt");
    std::vector<std::string> geneDataStore; //store file data in here
    //open both the data files
    int fileTwoSize=0;
    if(geneStream.is_open()){
        while(std::getline(geneStream, dataTwo)){
            geneDataStore.push_back(dataTwo);
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
    int numSuppressed = 0;

    std::vector<float> stationaryData;
    int stationary =0;
    float stationaryGenes;
    //set the initial mean of stationary
    float meanStationary = 0;
    int numStationary = 0;

    std::vector<float> expressedData;
    int expressed=0;
    float expressedGenes;
    //set the initial mean of expressed
    float meanExpressed = 0.5;
    int numExpressed = 0;

    //set the names of the clusters
    supp.setName("SuppressedGene");
    stat.setName("StationaryGene");
    expr.setName("Expressed Gene");

    //set the means of the clusters
    supp.setMean(meanSuppressed);
    stat.setMean(meanStationary);
    expr.setMean(meanExpressed);

    float initialData; //initialize a data variable to hold the data while sorting is happening
    
    float criteria = 1.0; //initialize it to anything above 0.0001 so it will enter while loop


    //create the output files
    std::ofstream suppressedFile;
    suppressedFile.open("suppressed_genes.txt");

    std::ofstream stationaryFile;
    stationaryFile.open("stationary_genes.txt");

    std::ofstream expressedFile;
    expressedFile.open("expressed_genes.txt");


    //set necessary variable in while loop to 0
    float newSuppMean = 0;
    float newStatMean = 0;
    float newExprMean = 0;
    
    float finalSuppMean = 0;
    float finalStatMean = 0;
    float finalExprMean = 0;

//while the criteria > 0.0001 - repeat steps 1-4
while(criteria >= 0.0001){
    //go through each data point in the logRatio file
    for(int j=0; j<fileOneSize; j++){
    

        initialData = logRatio[j];

        //first, for each log ratio data point calculate the distance of the point to each of the three cluster means.
        suppressedGenes = supp.dist(initialData);
        stationaryGenes = stat.dist(initialData);
        expressedGenes = expr.dist(initialData);
       // std::cout << suppressedG << "\n";

        //next. re-assign the data point to the closest cluster

        if((suppressedGenes <= stationaryGenes) && (suppressedGenes <= expressedGenes)){
            supp.getData() -> push_back((initialData));
            suppressed++; //increment the number of suppressed data points

        }
        else if((stationaryGenes <= suppressedGenes) && (stationaryGenes <= expressedGenes)){
            stat.getData() -> push_back((initialData));
            stationary++; //increment the number of stationary data points

        }
        else{
            expr.getData() -> push_back((initialData));
            expressed++; //increment the number of expressed data points
            //std::cout << "hi" << "\n";

        }

    }
    supp.getData() -> clear();
    stat.getData() -> clear();
    expr.getData() -> clear();


    //save final value of numbers of these three clusters
    numSuppressed = suppressed;
    numStationary = stationary;
    numExpressed = expressed;

    //next, recalculate the cluster means
    newSuppMean = statsDat.getMean(supp.getData(),suppressed);
    newStatMean = statsDat.getMean(stat.getData(),stationary);
    newExprMean = statsDat.getMean(expr.getData(),expressed);

    //next, calculate the sum of the absolute difference of the previous and current means
    finalSuppMean = supp.get_Mean() - newSuppMean;
    finalStatMean = stat.get_Mean() - newStatMean;
    finalExprMean = expr.get_Mean() - newExprMean;

    //recalculate the criteria
    criteria = abs(finalSuppMean)+abs(finalStatMean)+abs(finalExprMean);
    //std::cout << criteria << "\n";

    //clear the means and clear the data
    supp.setMean(newSuppMean);
    stat.setMean(newStatMean);
    expr.setMean(newExprMean);



    //RESET counters back to zero
    suppressed = 0;
    stationary = 0;
    expressed = 0;

    }//end while loop


    //next, output final cluster means to standard output 
	std::cout << "Suppressed Gene Final Mean: " << newSuppMean << "\n";
	std::cout << "Stationary Gene Final Mean: " << newStatMean << "\n";
	std::cout << "Expressed Gene Final Mean: " << newExprMean << "\n"; 
	std::cout << "Criteria: " << criteria << "\n";

    
    //write three output files, one for each of the final clusters: expressed_genes.txt, suppressed_genes.txt, stationary_genes.txt
    //each file should list the genes by name
    //a negative log ratio indicates suppression, log of zero is stationary, a positive log ratio indicates expression
    //supp<stationary<expressed -> 
    char gene_string[100];

    float stat_min = statsDat.getMin(stat.getData(),numStationary);
    float stat_max = statsDat.getMax(stat.getData(),numStationary);

    int totSum = numSuppressed + numStationary + numExpressed;

    //std::cout << "The number of Stationary Genes: "  << numStationary << "\n";
    //std::cout << "The number of Suppressed Genes: " << numSuppressed << "\n";
    //std::cout << "The number of Expressed Genes: " << numExpressed << "\n";
    if(logStream.is_open() && geneStream.is_open()){
        
        for(int j = 0; j < totSum; j++){
            initialData = logRatio[j];
            //std::cout << "hi";
            // >> gene_string;
            if(initialData < stat_min){
                suppressedFile << geneDataStore[j] << " " << initialData << "\n";
                //std::cout << gene_string << " " << initialData << "\n";
            }
            else if(initialData > stat_max){
                expressedFile << geneDataStore[j] << " " << initialData << "\n";
                //std::cout << gene_string << " " << initialData << "\n";
            }
            else{
                stationaryFile << geneDataStore[j] << " " << initialData << "\n";
                //std::cout << gene_string << " " << initialData << "\n";
            }
        }
    }



    //close all the data files
    suppressedFile.close();
    stationaryFile.close();
    expressedFile.close();
   

}
