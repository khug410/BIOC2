/* Name: Kelsey Hughes
  Date: 2/18/2022
  Details: This is a header file that declares the class. It will contain a function the sums all elements of an array, a function
  that subtracts one array from another, element by element, and a function that divides all values of an array by a concstant
  */

 #ifndef Kelsey2
 #define Kelsey2

 #include <fstream>
 #include <iostream>
 #include <vector>
 #include <math.h>

 namespace Vecties{
     class vectiesFunctions{
         public:
         void data(float addition, float sub, float div);
         
         //This function will sum all of the elements of an array
         // @param data: the array data that will be summed
         // @param size: the size of the array
         // @return: the sum of the array elements
         float sum(std::vector<float>* data, int size);

         //This function will subtract one array from the other array
         // @param data1: first data array
         // @param data2: second data array
         // @param size: the size of the first array
         // @return: the subtracted array values
         std::vector<float> subtraction(std::vector<float>* data1, int size, std::vector<float>* data2);

        //This function will divide all of the value of an array by a constant
        // @param data: vector array of data
        // @param size: the size of the vector
        // @param constant: constant
        // @return: the divided array values
        std::vector<float> division(std::vector<float>* data, int size, int constant);

        private:
            float addition;
            float sub;
            float div;
             
         };
 }

 #endif