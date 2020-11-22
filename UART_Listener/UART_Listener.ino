/*
  Multiple Serial test

  Receives from the main serial port, sends to the others.
  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:
  - any serial device attached to Serial port 1
  - Serial Monitor open on Serial port 0

  created 30 Dec 2008
  modified 20 May 2012
  by Tom Igoe & Jed Roach
  modified 27 Nov 2015
  by Arturo Guadalupi

  This example code is in the public domain.
*/

#ifdef DEBUG
  #define DEBUG_PRINT(x)  Serial.print (x)
  #define DEBUG_PRINTLN(x)  Serial.println (x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif
const byte arrayLength = 3;
byte serial1Array[arrayLength];
byte serial2Array[arrayLength];

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);                /*19(RX), 18(TX)*/
  Serial2.begin(9600);                /*17(RX), 16(TX)*/
}

void loop() {
  serial1Read();
  serial2Read();
  printSerial1Bytes();
  printSerial2Bytes();
  Serial.println();
}

void printSerial1Bytes(){
  Serial.print("serial1: ");
  for (byte i = 0; i < arrayLength; i++) {
    Serial.print(serial1Array[i]);
    Serial.print(" ");
    Serial.print("/t");
  }
}

void printSerial2Bytes(){
  Serial.print("serial2: ");
  for (byte i = 0; i < arrayLength; i++) {
    Serial.print(serial2Array[i]);
    Serial.print(" ");
    Serial.print("/t");
  }
}

void serial1Read(){
  if (Serial1.available()) {
    Serial1.readBytes(serial1Array, arrayLength);
  }
}

void serial2Read(){
  if (Serial2.available()) {
    Serial2.readBytes(serial2Array, arrayLength);
  }
}
