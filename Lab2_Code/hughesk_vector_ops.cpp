#include "hughesk_vector_ops.hpp"

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <fstream>

void Vecties::vectiesFunctions::data(float addition, float sub, float div){
    this -> addition = addition;
    this -> sub = sub;
    this -> div = div;

}

float Vecties::vectiesFunctions::sum(std::vector<float>* data, int size)
{
	int i = 0; 
	float addition = 0; 
	
	for (i=0; i<size; i++)
	{
		addition = addition + (*data)[i]; 
	}
	
	return addition; 

}

std::vector<float> Vecties::vectiesFunctions::subtraction(std::vector<float>* data1, int size, std::vector<float>* data2)  
{
	int j=0;
	int i=0;

	std::vector<float> subtraction; 
	  
	   // iterate through the array
	   for(j=0; j< size; j++) 
	   {
		   
		   subtraction.push_back(0); 
		 
	   }
	    for(i=0; i< size; i++) 
	   {
			subtraction[i] = ((*data1)[i] - (*data2)[i]); 
	   }
	   
	   return subtraction; 

}

std::vector<float> Vecties::vectiesFunctions::division(std::vector<float>* data, int size, int constant){

	int i = 0;
	int k = 0;

	std::vector<float> div;

	for(i=0;i<size;i++){
		div.push_back(0);
	}

	for(k=0;k<size;k++){
		div[k]=((*data)[k]/constant);
	}

	return div;
}
