#!/bin/bash


for((i=2; i <= "$1"/2; i++))
do
	if [ $(($1%i)) -eq 0  ]
	then
		echo "$1 is not a prime number."
		exit
	fi
done
echo "$1 is a prime number"
