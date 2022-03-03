#!/bin/bash

#Kelsey Hughes
#2/28/2022

dir=microarray

#prompt the user for the number of microarray points to be read in and processed
echo "How many microarray points are needed to be read in?"
read microPoints

if [ ${microPoints} -le 6118 ]
then
    out=hughesk_pre_processing.o

    if [ -f "summary.txt" ]
        then
    rm "summary.txt"
    fi 

    for i in {0..6}
    do 
    #preprocess every time point
    ./$out $dir/red_$i.dat $dir/red_background_$i.dat $dir/green_$i.dat $dir/green_background_$i.dat log_ratio_input_$i.dat $microPoints

    #copy the log ratio output data to a new file called log_ratio_input.dat
    cp log_ratio_input_$i.dat log_ratio_input.dat


    echo Time point $i: >> summary.txt
    #run clustering program on each
    ./hughesk_k_means.o log_ratio_input_$i.dat >> summary.txt

    #output to files
    cp expressed_genes.txt expressed_genes_$i.txt
    cp stationary_genes.txt stationary_genes_$i.txt
    cp suppressed_genes.txt suppressed_genes_$i.txt

	#write number genes in each cluster for summary file 
	echo number of suppressed genes: $(wc -l suppressed_genes.txt | cut -d ' ' -f 1) >> summary.txt 
	echo number of stationary genes: $(wc -l stationary_genes.txt | cut -d ' ' -f 1) >> summary.txt
	echo number of expressed genes: $(wc -l expressed_genes.txt | cut -d ' ' -f 1) >> summary.txt
	echo >> summary.txt

    done
else
    echo "The number of points exceeds 6118"
    exit 1
fi