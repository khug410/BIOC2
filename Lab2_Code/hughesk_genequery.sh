#!/bin/bash

#Name: Kelsey Hughes
#Date: 3/1/2022
#Details: This bash script will take the gene name as a command line argument and output what the gene is

echo "What is the gene name you would like to analyze?"
read geneName

for i in {0..6}
do

echo "In log_ratio_$i.dat:"
    if grep -F ${geneName} suppressed_genes_$i.txt 
    then
    echo "This gene is suppressed"

    elif grep -F ${geneName} expressed_genes_$i.txt
    then
    echo "This gene is expressed"

    elif grep -F ${geneName} stationary_genes_$i.txt 
    then
    echo "This gene is stationary"
    fi
done

