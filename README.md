# NFC Music Player

This Arduino project plays music, selected by using NFC tags. I don't have an LP record player, but I do have LP records - using this project, I can now "play" them.


## Build Guide

### Components
To build this, you will need an Arduino, an RFID tag reader/writer (mine is RC522 based) and a music player (YX5300), which can read files from a micro-SD and can be connected to normal speakers. This means: Three electrical components and some wires.

### Overview

Rough steps are:

1. Load tag-writer to your arduino, write data to your NFC tags.
2. Sort your music into folders, the folder names must exactly match "01", "02" etc.
3. Use `util/convert_files.sh` and `util/prefix_files.sh` to convert your music into the correct file format and to have them named in a way the music player understands.
4. Write the music to your SD card
5. Assemble
6. Load player-arduino to your arduino.
7. Hide the electronics and the tags in whatever manner you like. I added sheets of paper with strategically placed nfc-stickers into my vinyl sleeves.

### Sub-projects

#### player-arduino

This folder contains code for the actual end result. This can be loaded onto your arduino once the setup is done. Wiring is explained in `src/main.cpp`

#### tag-writer

To select music from the SD card, a folder index is read from the NFC tags. This program will allow you to write these indices to your tags. Prepare as many as you want/need. I recommend noting down the index on the tag.

#### util

For the sound module to read the cards, they have to be in a specific format and have to have a specific name. These two utility scripts will alow you to batch-convert and batch-rename one album at a time.

#### music/soundeffects

For giggles, I want scratchy noises when starting music. These can be found here. Note the license, if you want to use them.

#### case

Contains a prototype 3D-printable basic case for the electronic components. Not terribly pretty, but it hides the electronics well enough.

