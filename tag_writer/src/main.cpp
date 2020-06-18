#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid{ SS_PIN, RST_PIN };

MFRC522::MIFARE_Key key;
byte buffer[18];
byte buffer_size;


byte folder = 1;

void setup() {
	Serial.begin( 57600 );

	SPI.begin();
	rfid.PCD_Init();
	for ( byte i = 0; i < 6; i++ ) {
		key.keyByte[ i ] = 0xFF;
	}
}

void loop() {
	if ( !rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
		delay( 50 );
		return;
	}


	buffer[1] = folder;
	buffer_size = 1;
	rfid.MIFARE_Ultralight_Write(12, buffer, &buffer_size);
	folder++;

	buffer_size = 18;
	rfid.MIFARE_Read((byte) 12, buffer, &buffer_size );
	for ( unsigned char i : buffer ) {
		Serial.print( i < 0x10 ? " 0" : " " );
		Serial.print( i, HEX );
	}
	Serial.println();
	Serial.println();

	delay( 1000 );
}