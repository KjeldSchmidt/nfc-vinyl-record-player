#!/bin/bash

for filename in *; do
	new="${filename%.*}.mp3"
	ffmpeg -i "$filename" -vn -ar 44100  -ac 2 -b:a 320k "$new"
	if [ "$new" != "$filename" ]; then
		rm "$filename"
	fi
done
