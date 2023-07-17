#!/bin/bash

#Finder.sh

filesdir=$1
searchstr=$2

if [ -z "${filesdir}" ]
then
    echo "Invalid runtime argument for the file directory given."
    exit 1
fi

if [ -z "${searchstr}" ]
then
    echo "Invalid runtime argument for the search string given."
    exit 1
fi

if [ ! -d "${filesdir}" ]
then
    echo "Files directory is not actually a directory."
    exit 1
fi

numOfFilesInDir=$(find "${filesdir}" -type f | wc -l)
allFoundLines=$(grep -r "${searchstr}" "${filesdir}" | wc -l)

echo "The number of files are ${numOfFilesInDir} and the number of matching lines are ${allFoundLines}"
exit 0
