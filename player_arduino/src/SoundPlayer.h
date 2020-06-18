//
// Created by kjeld on 18/06/2020.
//

#ifndef VINYL_RECORD_PLAYER_SOUND_PLAYER_H
#define VINYL_RECORD_PLAYER_SOUND_PLAYER_H

#include <Arduino.h>
#include <MD_YX5300.h>

class SoundPlayer {
public:
	SoundPlayer( uint8_t i, uint8_t i1 );

	void play_folder( uint8_t folder );

	void begin();

	bool check();

private:
	MD_YX5300 mp3;
};


#endif //VINYL_RECORD_PLAYER_SOUND_PLAYER_H
