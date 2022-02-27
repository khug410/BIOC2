/* Name: Kelsey Hughes
   Date: 2/24/2022
   Details: This header file will declare the declaration for the cluster class. 
   This class stores the name of the object, the mean of the objects, and a vector of data points.
   It will also include distance function.
*/


#ifndef KelsClust
#define KelsClust

#include <vector>
#include <math.h>
#include <fstream>
#include <iostream>

namespace BigKelsCluster {
    class Cluster{
        public:

        //setter for the object name
        //@param objName: the name of the cluster being analyzed
        void setName(std::string objName);

        //getter for the object name variable
        //@returns: the string with cluster name
        std::string getName();

        //setter for the mean
        //@param objMean: the cluster mean
        void setMean(float objMean);

        //getter function for mean
        //@return: cluster mean
        float getMean();

        //setter for cluster data
        //@param data: vector of data in the cluset
        void setData(std::vector<float> data);

        //getter funcion for cluster data
        //@returns: the vector with data points from cluster
        std::vector<float>* getData();

        //getter for final data
        //@returns: the vector of final data
        float getFinalData(int final);

        //distance function of the distance from the data to the cluster object
        //@param datapoint: data points
        //@return: the distance
        float dist(float datapoint);

        private:
            std::string objName;
            float objMean;
            std::vector<float> data;




    };

}

#endif