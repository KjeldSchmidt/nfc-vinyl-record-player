#include <Arduino.h>
#include "SoundPlayer.h"
#include "../.pio/libdeps/nanoatmega328/MFRC522_ID63/src/MFRC522.h"
#include <MFRC522.h>
#include <SPI.h>

#define RST_PIN 9
#define SS_PIN 10

const uint8_t ARDUINO_RX = 4;    // connect to TX of MP3 Player module
const uint8_t ARDUINO_TX = 5;    // connect to RX of MP3 Player module
SoundPlayer player( ARDUINO_RX, ARDUINO_TX );

bool bUseCallback = true; // use callbacks?
bool bUseSynch = false;   // use synchronous?


MFRC522 rfid{ SS_PIN, RST_PIN };

MFRC522::MIFARE_Key key;

#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
	Serial.begin( 57600 );
	player.begin();
	delay( 500 );
	player.play_folder( 1 );

	SPI.begin();
	rfid.PCD_Init();
	for ( byte i = 0; i < 6; i++ ) {
		key.keyByte[ i ] = 0xFF;
	}
}

void loop() {
	player.check();

	if ( !rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
		delay( 50 );
		return;
	}

	byte buffer_size = 18;
	byte buffer[18];
	rfid.MIFARE_Read((byte) 12, buffer, &buffer_size );
	char folder_number = buffer[ 1 ];
	Serial.print( folder_number < 0x10 ? "0" : "" );
	Serial.println( folder_number, HEX );
	Serial.println();

	delay( 2000 );
}