#include <EEPROM.h>

void writeStringToEEPROM(int addrOffset, const String &strToWrite) {
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
    EEPROM.commit();
  }
}
String readStringFromEEPROM(int addrOffset) {
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0';
  return String(data);
}

String retrievedString;

void setup() {
  Serial.begin(9600);
  EEPROM.begin(512);
  writeStringToEEPROM(1, "Hello Arduino");
  retrievedString = readStringFromEEPROM(1);
  Serial.print("The String we read from EEPROM: ");
  Serial.println(retrievedString);
}

void loop() {
}
