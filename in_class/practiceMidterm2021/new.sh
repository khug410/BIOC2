#!/bin/bash

#3 arguments 

header=$1
refcount=$2
compcount=$3
#if i wanted to allow multiple countries to be passed in, i would use $@ to access additional countries 

if [[ ($# -ne 3) ]]
then
        echo expected 3 arguments. exiting
        exit 1
fi

if [ ! -f owid-covid-data.csv ] 
then
	echo covid data file does not exist. exiting
	exit 1
fi

if [[ ! $(grep $refcount owid-covid-data.csv) ]]
then
	echo $refcount does not exist
	exit 1
elif [[ ! $(grep $compcount owid-covid-data.csv) ]]
then
	echo $compcount does not exist
	exit 1
fi

#trying to figure out how to get the column number of the header name provided by input argument
#echo $head -n 1 owid-covid-data.csv | sed 's/[^,]//g' 

#displays the possible headers to the user 
#I know I would have to change how I do the arguemnts so the user could select from the list but I don't want to do that right now
#also i'm commenting it out cause I don't want to see it right now but it does work
#head -n1 owid-covid-data.csv | tr , '\n'

#takes all headers and puts it into an array (used to figure out which column to read from)
allhead="$(head -n1 owid-covid-data.csv | tr , '\n')"
headarray=($allhead)
echo all headers: ${#headarray[@]}
column=-1
for ((i=0;i<${#headarray[@]};i++))
do
	if [[ "${headarray[$i]}" = "$header" ]] 
	then 
		column=$i
		break
	fi
done

if [[ "$column" = "-1" ]] 
then 
	echo header does not exist
	exit 1
fi

#reading from the file, know that covid cases per million is in column 12 and country is in column 3
#i know this is not the most efficient way but i am running out of time so this is going to be good enough
while IFS=, read -r col1 col2 col3 col4 col5 col6 col7 col8 col9 col10 col11 col12 col13 col14 col15 col16 col17 col18 col19 col20 col21 col22 col23 col24 col25 col26 col27 col28 col29 col30 col31 col32 col33 col34 col36 col37 col38 col39 col40 col41 col42 col43 col44 col45 col46 col47 col48 col49 col50 col51 col52 col53 col54 col55 col56 col57 col58 col59
do 
	if [[ "$col3" == "$refcount" ]] 
	then
		#echo $col3 $col12
		date+=($col4)
		covpermil+=($col12)
	fi
	#this bit proves that I can get data for a second country
	#if [[ "$col3" = "$compcount" ]] 
	#then 
	#	echo $col3 $col12
	#fi

done < owid-covid-data.csv

#prints to the screen the covid per million for specified country
#shows that ref country is read correctly, data for country read from file
#for (( i=0;i<${#covpermil[@]};i++ )) 
#do 
#	echo ${covpermil[$i]}
#done


#calculate the monthly average -- going by date
#i'm having trouble with going by month, but i can sum all of the covpermil
#i'm trying to read the dates in, sum the covpermil, and if the month changes
#then divide sum by number of days, print to screen, reset sum for next month
currmonth=00
sum=0
for (( i=0;i<${#date[@]};i++ ))
do
	#echo ${date[$i]} |while IFS='-' read year month day
	#do
	#done
		sum=$(echo $sum+${covpermil[$i]} | bc -l)
done

echo sum: $sum

#echo sum: $sum > $refcount_$compcount_covid_comparison.txt
#it's not perfect but it writes something to a file and that is good enough
echo sum: $sum > {$refcount}_{$compcount}_covid_comparison.txt

