#!/bin/bash

#Kelsey Hughes
#3/2/2022

# download a cpp file from github - thanks gabborz for having a public github
#wget https://raw.githubusercontent.com/grohde1015/ubiquitous-succotash/main/Lab1/RohdeG_stats.cpp




#create new file to save the output to
touch /home/hughesk/BIOC2/in_class/header.txt

#extract all function headers and output them to a file
#save the grep to the file

grep -w "float GabeTheBabe::StatsBro" RohdeG_stats.cpp | sed -n 'float GabeTheBabe::StatsBro'>> header.txt

#determine the namespace of all functions, and add a line to the bottom of the same file
