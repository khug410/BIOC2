#!/bin/bash

#3 arguments
header=$1
ref=$2
comp=$3

#error checking for correct number of arguments
if [[ ($# -ne 3) ]]
then
    echo error. wrong number of arguments
    exit 1
fi

#check if file exists
if [ ! -f owid-covid-data.csv ]
then
    echo covid data file does not exist
    exit 1
fi

if [ -f "owid-covid-data.csv" ]
then
    rm "owid-covid-data.csv"
else
#download the csv file only once
wget https://github.com/owid/covid-19-data/blob/b80085548b15d458d9c8973acd91e55b11dee325/public/data/owid-covid-data.csv
fi
