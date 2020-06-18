#!/bin/bash

for filename in *; do
	ffmpeg -i "$filename" -vn -ar 44100  -ac 2 -b:a 320k "${filename%.*}.mp3"
	rm "$filename"
done
