#!/bin/bash

if [ $1 ] && [ $1 -eq $1 2>/dev/null ]
then

for((i=2; i <= "$1"/2; i++))
do
	if [ $(($1%i)) -eq 0  ]
	then
		echo "$1 is composite."
		exit
	fi
done
echo "$1 is a prime number"
else 
	echo "$1 is not a number."
fi
