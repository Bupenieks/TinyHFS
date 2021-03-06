
#include <Wire.h>
#include <String.h>
#include "File_Storage.h"


void writeByte(int deviceaddress, int eeaddress, char data ) {
  
  orbitBoosterWire.beginTransmission(deviceaddress);
  orbitBoosterWire.write((int)(eeaddress >> 8));   // MSB
  orbitBoosterWire.write((int)(eeaddress & 0xFF)); // LSB
  orbitBoosterWire.write(data);
  orbitBoosterWire.endTransmission();
 
  delay(5);
  
}

char readByte(int deviceaddress, int eeaddress) {
  char rdata = 0xFF;
  
  orbitBoosterWire.beginTransmission(deviceaddress);
  orbitBoosterWire.write((int)(eeaddress >> 8));   // MSB
  orbitBoosterWire.write((int)(eeaddress & 0xFF)); // LSB
  orbitBoosterWire.endTransmission();
 
  orbitBoosterWire.requestFrom(deviceaddress, 1);
 
  if(orbitBoosterWire.available()) rdata = orbitBoosterWire.read();

  return rdata;

}
