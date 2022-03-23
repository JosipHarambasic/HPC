#!/bin/bash

if ! [ $# -eq 1  ]; 
then
	echo "Too much arguments only 1 allowed!"
	exit
elif  [[ $1 ]] && [ $1 -eq $1 ];
then
	start=`date +%s.%N`
	factors=$(factor $1 | wc -w)

	if [ $factors -gt 2 ]; 
	then
		echo "$1 is composite." 
	else
		echo "$1 is prime." 
	fi
end=`date +%s.%N`
runtime=$(echo "$end - $start" | bc -l)
echo "The computation of this number took: 0$runtime seconds"
else 
	echo "$1 is not a number."	
fi
