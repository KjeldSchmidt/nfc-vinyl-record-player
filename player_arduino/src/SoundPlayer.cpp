//
// Created by kjeld on 18/06/2020.
//

#include "SoundPlayer.h"

SoundPlayer::SoundPlayer( const uint8_t RX_pin, const uint8_t TX_pin ) : mp3( MD_YX5300( RX_pin, TX_pin )) {}


void SoundPlayer::play_folder( uint8_t folder ) {
	current_folder_index = folder;
	current_file_index = 1;
	play_current();
}

void SoundPlayer::play_next() {
	current_file_index++;
	play_current();
}

void SoundPlayer::begin() {
	mp3.begin();
	mp3.setSynchronous( true );
	mp3.setCallback( nullptr );
}

bool SoundPlayer::check() {
	bool check = mp3.check();
	if ( check ) handle_message();
	return check;
}

void SoundPlayer::handle_message() {
	const MD_YX5300::cbData *status = mp3.getStatus();
	Serial.print(F( "STS_??? 0x" ));
	Serial.println( status->code, HEX );
	switch ( status->code ) {
		case MD_YX5300::STS_FILE_END:
		case MD_YX5300::STS_VERSION: // Boldly attempt to ignore errors.
			Serial.println( "Song done" );
			play_next();
			break;
		case MD_YX5300::STS_ERR_FILE:
			Serial.println( "File Not Found" );
			break;
		default:
			break;
	}
	Serial.println();
}

void SoundPlayer::play_current() {
	mp3.playSpecific( current_folder_index, current_file_index );
}
