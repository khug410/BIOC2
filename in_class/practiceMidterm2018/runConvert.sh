#!/bin/bash
# kelsey hughes
# 3/7/22
# running convertG42G4DCM.sh for every file

inputdir=$1
outputdir=$2

#how to double check if arguments are inputted correctly
if [ $# -ne 2 ];
then
    echo "please enter 2 directory names"
    exit
fi

#echo $inputdir
#echo $outputdir

#double check input directory exists
if [ ! -e $inputdir ]
then   
    echo "directory to $inputdir does NOT exist"
    exit 1
fi

#make output directory if it does not exist
#if [ ! -e $outputdir ]
#then
    mkdir -p $outputdir
#fi

directorysize=$(ls ${inputdir} | wc -l)
#echo $directorysize

for ((i=1;i<=$directorysize;i++));
do
    #echo $i
    #running bashscript for each file
    convertG42G4DCM.sh "${inputdir}/$i.g4" "${outputdir}/$i.g4dcm"
done

echo "it's all done!"