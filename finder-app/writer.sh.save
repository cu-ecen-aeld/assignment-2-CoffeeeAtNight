#!/bin/bash

#Writer.sh

writefile=$1
writestr=$2

if [ -z "${writefile}" ]
then
    echo "Invalid runtime argument for write file given."
    exit 1
fi

if [ -z "${writestr}" ]
then
    echo "Invalid runtime argument for write string given."
    exit 1
fi

mkdir -p "${writefile%/*}" && touch "${writefile}"

echo "${writestr}" > "${writefile}"

if [ ! -e "${writefile}" ]
then
    echo "File was not created."
    exit 1
fi

exit 0
