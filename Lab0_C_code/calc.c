/*Author: Kelsey Hughes---
 Date Created: 1/25/22--
 Function: This code will open a file, read the files contents, sum all of the content numbers, and output the sum into a new file*/

#include <stdio.h>
#include <stdlib.h>

int main(){
 int a;
 int i;
 int sum = 0;
 //create file objects for input and output files
 FILE *fp; 
 FILE *output;

 //open the input file in read mode
 fp = fopen("/home/hughesk/Lab0_C_code/numbers.txt", "r");
 
 //open the output file in write mode
 output = fopen("output.txt", "w");

 //error check for a NULL file
 if(fp == NULL){
     printf("error while opening file.\n");
 }

 //sum the numbers in the file
 for(i=1;i<=20; i++){
    fscanf(fp, "%d", &a);
    sum +=a;
    }

 //close input file
 fclose(fp);

 //print sum to a new file
 fprintf(output,"The sum of the numbers is %d\n", sum);

}



