#!/bin/bash

if ! [ $# -eq 1  ]; 
then
	echo "Too much arguments only 1 allowed!"
	exit
elif  [[ $1 ]] && [ $1 -eq $1 ];
then
	factors=$(factor $1 | wc -w)

	if [ $factors -gt 2 ]; 
	then
		echo "$1 is composite." 
	else
		echo "$1 is prime." 
	fi
else 
	echo "$1 is not a number."	
fi