#include "File_Storage.h"
#include "Defines.h"


void Write_File(String inData) {

    Serial.print("String received: ");
  
    // Work out length of data
    int str_len = inData.length() - 1;
    char str_bytes[str_len];
        
    // Split data into an array of char arrays, each one byte long
    for(int j = 0; j < str_len; j++) 
      str_bytes[j] = inData[j];

    // Print processed string
    for(int q = 0; q < str_len; q++)
      Serial.print(str_bytes[q]);
          
    // Write data to EEPROM
    for(int i = START_ADDRESS; i < START_ADDRESS + str_len; i++) 
      writeByte(EEPROM, i, str_bytes[i-START_ADDRESS]);
        
    Serial.print("\nDATA WRITTEN - length: ");
    Serial.print(str_len);
    Serial.println();
 
}


void Read_File(int str_len) {

  char str_bytes[str_len];

  Serial.println("DATA READ");

  // Read the data byte-by-byte and store in string str_bytes
  for(int i = START_ADDRESS; i < START_ADDRESS + str_len; i++)
    str_bytes[i-START_ADDRESS] = readByte(EEPROM, i);

  // Print out the read data
  for(int i = 0; i < str_len; i++)
    Serial.print((char) str_bytes[i]);

  Serial.println();

  
}



