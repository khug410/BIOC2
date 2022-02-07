#include "hughesk_corr.hpp"
#include "hughesk_stats.hpp"

//adding logic for the correlation function
float BigKelsCorr::correlation::corcof(std::vector<float>* data1, std::vector<float>* data2, int n)
{

	BigKels::Stattys data; //instantiate for mean calculation
	
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