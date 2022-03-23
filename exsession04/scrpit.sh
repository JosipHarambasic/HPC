#!/bin/bash

if [ -f $1 ] && [ ! -z $1 ] ; 
then
	cat $1 | while read line 
	do 	
		echo $line
		echo -e "\n"
	done
else 
	echo "$1 does not exist."
fi




