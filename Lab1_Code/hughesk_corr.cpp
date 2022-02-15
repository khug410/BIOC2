/*Name: Kelsey Hughes
Date: 2/6/22
Details: This is the file that defines the logic for a program that will estimate the correlation coefficient between two data sets
*/

#include "hughesk_corr.hpp"
#include "hughesk_stats.hpp"
#include <math.h>


//adding logic for the correlation function
float BigKelsCorr::correlationFunctions::corrcof(std::vector<float>* data1, std::vector<float>* data2, int n)
{

	BigKels::Stattys data; //instantiate a variable for mean calculation
	
	// variables needed for calculating the correlation coefficient -- some of these ended up being not necessary was just trying to work through equation
	float num  = 0; // numerator 
	float denom = 0; // denominator
	float leftDenom = 0; // left half of denominator
	float rightDenom = 0; // right half of denominator
	float corr = 0; //return value	
	float xSquared = 0; 
	float ySquared = 0; 

    float xSum = 0;
	float ySum = 0; 
	float totSum = 0;
	float Mean1 = 0; // using mean function 
	float Mean2 = 0; // using mean function 
	float sumSquared = 0;
	float sumSquared2 = 0;
	float meanSquared = 0;
	float meanSquared2 = 0;
	float xySum = 0;
    float xMeanSquared = 0;
	float yMeanSquared = 0; 
	float cor = 0;



	int i = 0; 

	// incrementing through the arrays and calculating stats needed in the equation
	for(i=0; i<n; i++) {
		totSum = totSum + (*data1)[i] * (*data2)[i];
	}

	//get both of the means
	Mean1 = data.getMean(data1, n);
	Mean2 = data.getMean(data2, n);

	//calculate the numerator of the equation
	num = totSum - (n*Mean1*Mean2); 

	//two for loops to get means on two different data sets
	for (int i=0; i<n; i++){
		sumSquared = sumSquared + (*data1)[i] * (*data1)[i];
	}

	//get the new mean for first array
	meanSquared = data.getMean(data1,n);
	meanSquared = meanSquared * meanSquared;

	//use for loop to get sum of the squared data
	for(int i = 0; i<n; i++){
		sumSquared2 = sumSquared2 + (*data2)[i] * (*data2)[i];
	}

	//get the new mean for second array
	meanSquared2 = data.getMean(data2,n);
	meanSquared2 = meanSquared2 * meanSquared2;


	//calculate denominator based on equation
	leftDenom = sumSquared - (n*meanSquared);
	rightDenom = sumSquared2 - (n*meanSquared2);

	denom = leftDenom*rightDenom;

	denom = sqrt(denom);

	cor = num/denom;

	return cor;


}