

#ifdef DEBUG
  #define DEBUG_PRINT(x)  Serial.print (x)
  #define DEBUG_PRINTLN(x)  Serial.println (x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif
const byte arrayLength = 4;
byte serial1Array[arrayLength];
byte serial2Array[arrayLength];

void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  Serial1.begin(9600);                /*19(RX), 18(TX)*/
  Serial2.begin(9600);                /*17(RX), 16(TX)*/
}

void loop() {
  if((Serial1.available() > 0) || (Serial2.available() > 0)){
    serial1Read();
    serial2Read();
    printSerial1Bytes();
    printSerial2Bytes();
    printTimestamp();
    Serial.println();
  }
}

void printSerial1Bytes(){
  Serial.print("serial1: ");
  for (byte i = 0; i < arrayLength; i++) {
    Serial.print(serial1Array[i], HEX);
    Serial.print(" ");
    Serial.print("\t");
  }
}

void printSerial2Bytes(){
  Serial.print("serial2: ");
  for (byte i = 0; i < arrayLength; i++) {
    Serial.print(serial2Array[i], HEX);
    Serial.print(" ");
    Serial.print("\t");
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

void printTimestamp(){
  Serial.print(millis());
}
