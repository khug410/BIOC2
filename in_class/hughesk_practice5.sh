#!/bin/bash

#Kelsey Hughes
#3/2/2022

# download a cpp file from github - thanks gabborz for having a public github
wget -nc https://raw.githubusercontent.com/grohde1015/ubiquitous-succotash/main/Lab1/RohdeG_stats.cpp




#create new file to save the output to
touch /home/hughesk/BIOC2/in_class/header.txt

#extract all function headers and output them to a file
#save the grep to the file

#grep ".hpp" RohdeG_stats.cpp | sed 's/#include //g' | sed 's/ ?*"//g' 
#function headers
grep ".*::.*(" < RohdeG_stats.cpp | sed 's/^[^::]*:://' | sed 's/^[^::]*:://' | sed 's/{//g'> header.txt

#print out the namespace

echo "namespace:" >> header.txt
#add line to bottom of same file
grep "namespace" RohdeG_stats.cpp | sed 's/using namespace \(.*\);/\1/'>> header.txt


#grep "GabeTheBabe::" RohdeG_stats.cpp | sed 's/GabeTheBabe::StatsBro:://g' > header.txt

#determine the namespace of all functions, and add a line to the bottom of the same file
#grep "::" RohdeG_stats.cpp | sed 's/float //g' | sed 's/ ?*//g' | cut -d ":" -f 1 >> header.txt