#!/bin/bash
#Kelsey Hughes
#2/16/2022
#This is a bash script about conditionals!

#echo the intro to Bad Romance to the terminal using 6 variables, a for loop, and if statements
str1="Oh-oh-oh-oh-oh-oh-oh, oh-oh-oh"
str2="Caught in a bad romance"
str3="Ra-ra-ah-ah-ah"
str4="Roma Roma-ma"
str5="Gaga, Ohh la-la"
str6="Want your bad romance"

#echo the appropriate line
for i in {1..12}
    do 
        if [[ ($i -eq 1) || ($i -eq 3) ]]
            then
                echo ${str1}
        elif [[ ($i -eq 2) || ($i -eq 4) ]]
            then 
                echo ${str2}
        elif [[ ($i -eq 5) || ($i -eq 9) ]]
            then    
                echo ${str3}
        elif [[ ($i -eq 6) || ($i -eq 10) ]]
            then    
                echo ${str4}
        elif [[ ($i -eq 7) || ($i -eq 11) ]]
            then    
                echo ${str5}
        else
            echo ${str6}
        fi
    done

# Part2

while read -r line

do

    if [ "./good_movies.txt" ]

    then

        if [ "$line" == "A Cinderella Story" ]
        then
            echo ${line} 
        fi

    fi

done<"good_movies.txt"
