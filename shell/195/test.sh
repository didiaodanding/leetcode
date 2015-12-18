#!/bin/bash
i=0
while read line
do
	aa[i]=$line 
	let i=$i+1
done < file.txt
number=${#aa[*]}
if [ $number -lt 10 ] ; then
	echo ""
else
	echo ${aa[9]}
fi
