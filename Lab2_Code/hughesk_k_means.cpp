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
    std::ifstream geneStream;
    geneStream.open("gene_list.txt");
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

    float initialData; //initialize a data variable to hold the data while sorting is happening
    
    float criteria = 1.0;


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
        std::cout << expressedGenes << "\n";

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

    //next, recalculate the cluster means
    newSuppMean = statsDat.getMean(supp.getData(),suppressed);
    newStatMean = statsDat.getMean(stat.getData(),stationary);
    newExprMean = statsDat.getMean(expr.getData(), expressed);

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

    supp.getData() -> clear();
    stat.getData() -> clear();
    expr.getData() -> clear();


    
    }//end while loop



    
    //write three output files, one for each of the final clusters: expressed_genes.txt, suppressed_genes.txt, stationary_genes.txt
    //each file should list the genes by name

/*
    //a negative log ratio indicates suppression, log of zero is stationary, a positive log ratio indicates expression
    //supp<stationary<expressed -> 


    int count1 = 0;
    int count2 = 0;
    
   // std::cout << stat.getFinalData(count2);
    //std::cout <<logRatio[count1];
    //std::cout << stationary;
    if((finalSuppMean < finalStatMean) && (finalStatMean < finalExprMean)){
        //list the genes by name
        for(count1 = 0; count1 < fileOneSize; count1++){
            //increment through each cluster
            for(count2 = 0; count2 < suppressed; count2++){
                if(logRatio[count1] == supp.getFinalData(count2)){
                    suppressedFile << geneDataStore[count1];
                    suppressedFile << "\n";
                }
            }
            for(count2 = 0; count2 < stationary; count2++){
                if(logRatio[count1] == stat.getFinalData(count2)){
                    stationaryFile << geneDataStore[count1];
                    stationaryFile << "\n";
                }
            }
            for(count2; count2 < expressed; count2++){
                if(logRatio[count1] == expr.getFinalData(count2)){
                    expressedFile << geneDataStore[count1];
                    expressedFile << "\n";
                }
            }
        }
    }


}*/
    //close all the data files
    suppressedFile.close();
    stationaryFile.close();
    expressedFile.close();
   

}
