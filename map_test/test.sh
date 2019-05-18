#!/bin/bash
size=2
while [ $size -lt 10 ]
do
size=$((size+1))
counter=0
	while [ $counter -lt 30 ]
	do
		counter=$((counter+1))
		echo "size : $size  || counter : $counter"
		python generator.py $size -u > hello.txt
		./n-puzzle hello.txt -m -uniform
	done
done
