#!/bin/bash

a=1
for filename in *; do
	new=$(printf "%03d--%s" "$a" "$filename")
	mv -- "$filename" "$new";   let a=a+1
done
