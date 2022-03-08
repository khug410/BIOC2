#!/bin/bash
# kelsey hughes
# 3/7/22
# splicing datasets for 2D CT images

# how to calculate relationship between g4 and g4dcm file
#slice_coord1=slice_index1*slice_thickness - total_slices*slice_thickness/2

input=$1
output=$2

#how to double check if arguments are inputted correctly
if [ $# -ne 2 ];
then
    echo "please enter 2 directory names"
    exit
fi

#getting directory name from input
DIR="$(dirname "${input}")"

#getting only file name from input
FILEinput="$(basename "${input}")"

#echo ${DIR}
#echo ${FILEinput}

#double check both files exist
if [ ! -e $input ]
then   
    echo "directory to $input does NOT exist"
    exit 1
fi

#delete output file if it exists (refresh output file)
if [ -e $output ]
then
    rm $output
fi

data1="data1"
data2="data2"

#handling for data1 --- number of lines to keep are different!!!! 
if [[ $input == *"$data1"* ]]; 
then
    #echo "working with $data1 within directory $input"
    #copying lines 1-15 because they are the same
    i=1
    while read line;
    do
        if [ $i -le 15 ]
        then
            #handle lung on line 3
            if [ $i -eq 3 ]
            then
                echo "1 LungInhale" >> $output
                let i=$i+1
            #handle adipose on line 12
            elif [ $i -eq 12 ]
            then
                echo "10 AdiposeTissue" >> $output
                let i=$i+1
            else
                echo $line >> $output
                let i=$i+1
            fi
        fi
    done < $input

    #saving line 16 in input -- slice thickness
    slicethick=$(sed -n 16p $input)
    #echo $slicethick

    #saving line 17 of input -- start & end slice indices
    sliceindices=$(sed -n 17p $input)
    #echo $sliceindices

    #getting indices from line 17 to use for coordinate math
    index1=$(echo $sliceindices | cut -d ' ' -f 1)
    #echo $index1
    index2=$(echo $sliceindices | cut -d ' ' -f 2)
    #echo $index2

    #saving line 18 of input -- last line
    line18=$(sed -n 18p $input)
    #echo $line18

    slicecount=$(ls ${DIR} | wc -l)
    #echo $slicecount

    #do math to calculate slice coordinates
    slicecoord1=$(echo "scale=3;$index1*$slicethick - $slicecount*$slicethick/2.0" | bc -l)
    #echo $slicecoord1
    slicecoord2=$(echo "scale=3;$index2*$slicethick - $slicecount*$slicethick/2.0" | bc -l)
    #echo $slicecoord2

    #printing to finalize g4dcm file
    echo "$slicecoord1 $slicecoord2" >> $output
    echo $line18 >> $output
fi

if [[ $input == *"$data2"* ]];
then

    #working with data2 -- lines to keep are different!! 
    #echo "you are working with $data2 in directory $input"

    i=1
    while read line;
    do
        if [ $i -le 10 ]
        then
            #handle lung on line 3
            if [ $i -eq 3 ]
            then
                echo "1 LungInhale" >> $output
                let i=$i+1
            #handle adipose on line 7
            elif [ $i -eq 7 ]
            then
                echo "5 AdiposeTissue" >> $output
                let i=$i+1
            else 
                echo $line >> $output
                let i=$i+1
            fi
        fi
    done < $input

    #saving line 11 in input -- slice thickness
    slicethick=$(sed -n 11p $input)
    #echo $slicethick

    #saving line 12 of input -- start & end slice indices
    sliceindices=$(sed -n 12p $input)
    #echo $sliceindices

    #getting indices from line 12 to use for coordinate math
    index1=$(echo $sliceindices | cut -d ' ' -f 1)
    #echo $index1
    index2=$(echo $sliceindices | cut -d ' ' -f 2)
    #echo $index2

    #saving line 13 of input -- last line
    line13=$(sed -n 13p $input)
    #echo $line13

    slicecount=$(ls ${DIR} | wc -l)
    #echo $slicecount

    #do math to calculate slice coordinates
    slicecoord1=$(echo "scale=3;$index1*$slicethick - $slicecount*$slicethick/2.0" | bc -l)
    #echo $slicecoord1
    slicecoord2=$(echo "scale=3;$index2*$slicethick - $slicecount*$slicethick/2.0" | bc -l)
    #echo $slicecoord2

    #printing to finalize g4dcm file
    echo "$slicecoord1 $slicecoord2" >> $output
    echo $line13 >> $output
fi
