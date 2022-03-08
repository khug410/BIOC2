#!/bin/bash

#3 arguments
#header=$1
refcount=$1
#comp=$3

#error checking for correct number of arguments
#if [[ ($# -ne 3) ]]
#then
 #   echo error. wrong number of arguments
  #  exit 1
#fi



#download the csv file only once
wget -nc https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/owid-covid-data.csv


#check if file exists
if [ ! -f owid-covid-data.csv ]
then
    echo covid data file does not exist
    exit 1
fi

#echo "2+2+2.5" | bc -l



#takes all headers and puts it into an array (used to figure out which column to read from)
allhead="$(head -n1 owid-covid-data.csv | tr , '\n')"
#echo $allhead
headarray=($allhead)
#echo all headers: ${#headarray[@]}
column=-1
for ((i=0;i<${#headarray[@]};i++))
do
  #echo "${headarray[$i]}"
  #echo $i
	if [[ "${headarray[$i]}" = "$header" ]] 
	then 
		column=$i #says which specific column to look at
		break
	fi
done

#error checking for the correct header
#if [[ "$column" = "-1" ]] 
#then 
	#echo header does not exist
	#exit 1
#fi

while IFS=, read -r col1 col2 col3 col4 col5 col6 col7 col8 col9 col10 col11 col12 col13 col14 col15 col16 col17 col18 col19 col20 col21 col22 col23 col24 col25 col26 col27 col28 col29 col30 col31 col32 col33 col34 col36 col37 col38 col39 col40 col41 col42 col43 col44 col45 col46 col47 col48 col49 col50 col51 col52 col53 col54 col55 col56 col57 col58 col59
do 
  #echo $col3
	if [[ "$col3" == "$refcount" ]] 
	then
		#echo $col3 
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
#shows that ref country is read correctly, data for country read from file -- working
#for (( i=0;i<${#covpermil[@]};i++ )) 
#do 
#	echo ${covpermil[$i]}
#done

#calculate the monthly average\
#month=00
sum=0.0
data=0
for (( i=0;i<${#date[@]};i++ ))
do
  #echo hi
	#echo ${date[$i]} |while IFS='-' read year month day
	#do
	#done
		#sum=$(echo $sum+${covpermil[$i]} | bc -l)
  #echo *"${date[$i]}"*
  #if [ "2020-03???*" == *"${date[$i]}"* ]
  #then
    #echo hi
    #month=0
    #echo "pre ${sum[$month]}"
    #echo "pre2 ${covpermil[$i]}"
  #fi
  #extract just the dates
  newDate=$(echo "${date[$i]}" | sed 's/.....//' | sed 's/-..//')
  #echo $newDate
  pastDate=$(echo "${date[$i-1]}" | sed 's/.....//' | sed 's/-..//')

  #find the difference between the two dates
  difference=$(echo "$newDate - $pastDate" | bc -l)
  #echo $presentDate
  
    k=0
    if [ $difference == 1 ]
    then 
      #monthDate=${date[$i]}
      #echo $monthDate
      #else sum the covid cases
      sum=$(echo "$sum + ${covpermil[$i]}" | bc -l)
      ((data=data+1))
    else
      avg=$(echo "$sum/$data" | bc -l)
      ((month=month+1))
      sum=0
      data=1
      sum=$(echo "$sum + ${covpermil[$i]}" | bc -l)
    
    fi

  #echo $sum
  
month=$(echo "$month-1" | bc -l )
#echo "done country 1"
echo "avg 0: ${avg[month]}"
  
  #echo $number
done


