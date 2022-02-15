#! bin/sh

#Name: Kelsey Hughes
#Date: February 11, 2022
#Correlation analysis for anesthetic concentrations. A total of 59 correlations coefficients will be found.

#Prompt the user to enter a concentration level to analyze

echo "Enter the concentration level to analyze: "
read concentrationLevel
echo "Chosen concentration is ${concentrationLevel}"


#error checking to see if it is a valid input
if [ ${concentrationLevel} == '0' ] || [ ${concentrationLevel} == '5' ]

then

    #compile the correlation file

    g++ -o outc hughesk_corr_test.cpp hughesk_corr.cpp hughesk_stats.cpp

 

    #avoids excess storage

    if [ "./conc_corr_${concentrationLevel}.csv" ]

    then

        echo "Delete existing file"

        rm -r "./conc_corr_${concentrationLevel}.csv"

    fi
    #create new file
    touch /home/hughesk/BIOC2/Lab1_Code/conc_corr_${concentrationLevel}.csv

 

    #file names are slightly different in terms of a . so have to do it in two if statements

    if [ ${concentrationLevel} == '0' ]  
    then
        #do it for all 59 epochs
        for i in {1..59}

        do

            #print 1vs2, 2vs3, etc
            echo -n "${i}vs$((i+1)), " >> conc_corr_${concentrationLevel}.csv

            #send data to csv file every time
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