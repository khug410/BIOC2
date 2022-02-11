#! bin/sh
#Kelsey Hughes
#2/8/22
#This bash script will be used for histogram analysis

#prompt user for the concentration level to analyze
echo "Enter the concentration level to be analyzed"
read levelConcentration
echo "The concentration level is: $levelConcentration"

touch concentrationData.txt

#concate the files based on concentration level
cat /home/hughesk/BIOC2/Lab1_Code/EEG_DATA/ERP0$levelConcentration??*.txt >> concentrationData.txt

#move the data so it remains in the EEG_DATA directory
mv ./concentrationData.txt ./EEG_DATA/concentrationData.txt

#copy the new data file to a file called catted_input.dat
touch catted_input.dat
cp ./EEG_DATA/concentrationData.txt ./catted_input.dat

#execute the histogram program 
g++ -o out1 hughesk_stats_test.cpp -lm

touch histiedata_$levelConcentration.txt

./out1 "./catted_input.dat"
./out1 "./catted_input.dat" > histiedata_$levelConcentration.txt

mv histiedata_$levelConcentration.txt ./EEG_DATA/histiedata_$levelConcentration.txt

echo "The output is stored "
find $PWD -type f | grep "histiedata_$levelConcentration.txt"