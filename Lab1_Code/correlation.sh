#! bin/sh

#Name: Kelsey Hughes
#Date: February 11, 2022
#Correlation analysis for anesthetic concentrations. A total of 59 correlations coefficients will be found.

#Prompt the user to enter a concentration level to analyze

echo "Enter the concentration level to analyze: "
read concentrationLevel
echo "Chosen concentration is ${concentrationLevel}"

 

# first if statement is to check for a valid file name

if [ ${concentrationLevel} == '0' ] || [ ${concentrationLevel} == '5' ]

then

 

    #use a loop to compare the files consecutively

    g++ -o outc hughesk_corr_test.cpp hughesk_corr.cpp hughesk_stats.cpp

 

    # create file and delete if it already exists

    if [ "./conc_corr_${concentrationLevel}.csv" ]

    then

        echo "Deleting the already existing file with that concentration"

        rm -r "./conc_corr_${concentrationLevel}.csv"

    fi

 

    touch /home/hughesk/BIOC2/Lab1_Code/conc_corr_${concentrationLevel}.csv

 

    # file names are slightly different

    if [ ${concentrationLevel} == '0' ]  

    then

        for i in {1..59}

        do

            echo -n "${i}vs$((i+1)), " >> conc_corr_${concentrationLevel}.csv

            ./outc "/home/hughesk/BIOC2/Lab1_Code/EEG_DATA/ERP0${concentrationLevel}${i}.txt" "/home/hughesk/BIOC2/Lab1_Code/EEG_DATA/ERP0${concentrationLevel}$((i+1)).txt" >> /home/hughesk/BIOC2/Lab1_Code/conc_corr_${concentrationLevel}.csv


        done

 

    elif [ ${concentrationLevel} == '5' ]

    then

        for i in {1..59}

        do

            echo -n "${i}vs$((i+1)), " >> conc_corr_${concentrationLevel}.csv

            ./outc "/home/hughesk/BIOC2/Lab1_Code/EEG_DATA/ERP0${concentrationLevel}.${i}.txt" "/home/hughesk/BIOC2/Lab1_Code/EEG_DATA/ERP0${concentrationLevel}.$((i+1)).txt" >> /home/hughesk/BIOC2/Lab1_Code/conc_corr_${concentrationLevel}.csv


        done

    fi

 


 

else

    echo "She does not exist!"

    exit 1

fi