//
// Created by kjeld on 18/06/2020.
//

#include "SoundPlayer.h"

SoundPlayer::SoundPlayer( const uint8_t RX_pin, const uint8_t TX_pin ) : mp3( MD_YX5300( RX_pin, TX_pin )) {}


void SoundPlayer::play_folder( uint8_t folder ) {
	mp3.playFolderRepeat( 1 );
}

void SoundPlayer::begin() {
	mp3.begin();
	mp3.setSynchronous( false );
	mp3.setCallback( nullptr );
	//mp3.volume( mp3.volumeMax());
}

bool SoundPlayer::check() {
	return mp3.check();
}
