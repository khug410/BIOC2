#!/bin/sh
##Kelsey
##3/5/21
##comments:This is my shell script the midterm



if [ ! -f "owid-covid-data.csv" ]                   #set up all the variables in int form instead of string
then
    wget https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/owid-covid-data.csv -c covid_data.csv
fi

if [ ! $1 ]
then
    echo "No first input"
    exit 1
fi

if [ ! $2 ]
then
    echo "No second input"
    exit 1
fi
arr_csv=() 

num_rows=0
num_rows_start=0
num_rows_end=0
num_rows_start2=0
num_rows_end2=0

#https://www.xmodulo.com/read-column-data-text-file-bash.html#:~:text=To%20read%20column%20data%20from%20a%20file%20in%20bash%2C%20you,%2Dof%2Dfile%20is%20reached.
while IFS=, read -ra fields; do
    location[num_rows]=${fields[2]}
    date[num_rows]=${fields[3]} 
    new_cases_per_million[num_rows]=${fields[11]} 

    if [[ ${location[num_rows]} == *"$1"* ]]
    then
        if [ ! $num_rows_start = 0 ]
        then
            true
        else
           num_rows_start=$num_rows 
        #    echo "blah $num_rows_start"
        fi 
    else
        if [ $num_rows_start -gt 0 ]
        then
            if [ $num_rows_end = 0 ]
            then
                num_rows_end=$(echo "$num_rows-1" | bc -l )
                # echo "hehehe $num_rows_end"
            fi
        fi       
    fi

    if [[ ${location[num_rows]} == *"$2"* ]]
    then
        if [ ! $num_rows_start2 = 0 ]
        then
            true
        else
           num_rows_start2=$num_rows 
        #    echo "blah $num_rows_start"
        fi 
    else
        if [ $num_rows_start2 -gt 0 ]
        then
            if [ $num_rows_end2 = 0 ]
            then
                num_rows_end2=$(echo "$num_rows-1" | bc -l )
                # echo "hehehe $num_rows_end"
            fi
        fi       
    fi
    ((num_rows=num_rows+1))
done < "owid-covid-data.csv"

if [ $num_rows_end = 0 ]
then
    num_rows_end=$num_rows
fi

if [ $num_rows_end2 = 0 ]
then
    num_rows_end2=$num_rows
fi

#https://linuxhint.com/check-the-number-of-arguments-in-bash/#:~:text=The%20%24%23%20special%20variable%20always,to%20any%20specific%20Bash%20script.
echo "the passed arguments are:"
echo $@
echo "the total number of arguments is:"
echo $#
index=0
sum=0.0
data=0
index2=0
sum2=0.0
data2=0

past=0
curr_day=0
past2=0
curr_day2=0

for (( index=$num_rows_start;index<$num_rows_end;index++))
do
    if [ ${new_cases_per_million[$index2]} ]
    then
        if [ $(echo ${date[$index]} | sed 's/........//') -gt $curr_day ]
        then
            sum=$(echo "$sum + ${new_cases_per_million[$index]}" | bc -l )
            curr_day=$(echo ${date[$index]} | sed 's/........//')
            # echo "day: $curr_day"
            ((data=data+1))
        else
            avg[month]=$(echo "$sum/$data" | bc -l )
            # echo "avg ${avg[$month]}"
            start_date[month]=${date[$index]}
            ((month=month+1))
            sum=0
            data=1
            sum=$(echo "$sum + ${new_cases_per_million[$index]}" | bc -l )
            curr_day=$(echo ${date[$index]} | sed 's/........//')
        fi
    fi    
done

month=$(echo "$month-1" | bc -l )
maxmonth1=$month

month2=0
data=0
curr_day2=0
for (( index2=$num_rows_start2;index2<$num_rows_end2;index2++))
do
    if [ ${new_cases_per_million[$index2]} ]
    then
        if [ $(echo ${date[$index2]} | sed 's/........//') -gt $curr_day2 ]
        then
            sum2=$(echo "$sum2 + ${new_cases_per_million[$index2]}" | bc -l )
            curr_day2=$(echo ${date[$index2]} | sed 's/........//')
            #  echo "day: $curr_day2"
            ((data2=data2+1))
        else
            avg2[month2]=$(echo "$sum2/$data2" | bc -l )
            #  echo "avg ${avg[$month]}"
            start_date2[month2]=${date[$index2]}
            ((month2=month2+1))
            sum2=0
            data2=1
            sum2=$(echo "$sum2 + ${new_cases_per_million[$index2]}" | bc -l )
            curr_day2=$(echo ${date[$index2]} | sed 's/........//')
        fi
    fi    
done
month2=$(echo "$month2-1" | bc -l )
maxmonth2=$month2


for(( i=0;i<$maxmonth2;i++))
do
    echo "$1 ${start_date[$i]}">>"$1_$2_covid_comparision.txt"
    echo "Average: ${avg[$i]}">>"$1_$2_covid_comparision.txt"
    echo "$2 ${start_date2[$i]}">>"$1_$2_covid_comparision.txt"
    echo "Average: ${avg2[$i]}">>"$1_$2_covid_comparision.txt"

done