#!/bin/bash

#1 arguments
#header=$1


#error checking for correct number of arguments
#if [[ ($# -ne 1) ]]
#then
    #echo error. wrong number of arguments
    #exit 1
#fi

#extract and display to the console
file=$1
prevline=0
while read -r line
do
	if [[ $line == //* || "$line"  == "/*"* || "$line" == "*"* ]] 
	then
		echo "$line" | grep -Po "^.{2}\K.*" | sed -e 's/^[ \t]*//' >> new.txt
		prevline=1
	elif [[ $prevline == 1 ]] 
	then
		echo "-------------------------------------" >> new.txt
		prevline=0
	else
		prevline=0
	fi
	

done < "$file"