#include "hughesk_corr.hpp"
#include "hughesk_stats.hpp"

//adding logic for the correlation function
float BigKelsCorr::correlationFunctions::corrcof(std::vector<float>* data1, std::vector<float>* data2, int n)
{

	BigKels::Stattys data; //instantiate a variable for mean calculation
	
	// variables needed for calculating the correlation coefficient 
	float num  = 0; // numerator 
	float denom = 0; // denominator
	float leftDenom = 0; // left half of denominator
	float rightDenom = 0; // right half of denominator
	float corr = 0; //return value	
	float xSquared = 0; 
	float ySquared = 0; 

    float xSum = 0;
	float ySum = 0; 
	float xMean = 0; // using mean function 
	float yMean = 0;; // using mean function 
	float xySum = 0;
    float xMeanSquared = 0;
	float yMeanSquared = 0; 



	int i = 0; 

	// incrementing through the arrays 
	for(i=0; i<n; i++) 
	{
		
		// y sum 
		ySum = ySum + (*data2)[i]; 
		
		// y squared  
		ySquared = ySum * ySum; 
	
		// x sum
		xSum = xSum + (*data1)[i]; 
		
		// x squared 
		xSquared = xSum * xSum; 
		 
		// find total
		xySum = xSum + ySum; 

		 
	}
	
	// finding the mean of x and y 
     xMean = data.getMean(data1, n); // finding the mean of x
     yMean = data.getMean(data2, n); // finding the mean of y
    // mean squared 
	xMeanSquared = xMean * xMean; // mean squared  
	yMeanSquared = yMean * yMean; // mean squared 
	
	// finding numerator & denominator
	num = ((n * xSum * ySum) -  (n * xMeanSquared));
        
	// 
	leftDenom = ((n * xSquared) -  (n * xMeanSquared)); 
	rightDenom = ((n * ySquared) - (n * yMeanSquared)); 
	
	// denominator final
	denom = sqrt(leftDenom * rightDenom); 
	 
	// return value
	corr = num/denom; 

	return corr; 
}

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
    if(argc < 2){
        std::cout << "Need two arguments. \n";
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

