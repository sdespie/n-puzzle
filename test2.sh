#!/bin/bash
size=2
while [ $size -lt 10 ]
do
size=$((size+1))
counter=0
	while [ $counter -lt 100 ]
	do
		counter=$((counter+1))
		echo "size : $size  || counter : $counter"
		python generator.py $size -s > hello.txt
		./n-puzzle hello.txt -m -uniform
	done
done
