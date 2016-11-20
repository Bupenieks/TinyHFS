#include "File_Storage.h"
#include "Defines.h"
#include <stdlib.h>
#include <OrbitBoosterPackDefs.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include "Energia.h"

String        data;

long          lBtn1;

int           strRcvd = 0;

int           once = 2;



char readByte(int deviceaddress, int eeaddress);
void writeByte(int deviceaddress, int eeaddress, char data );
void Write_File(String inData);
void Read_File(int str_len);




void setup(void) {
  

  Serial.begin(9600);
  orbitBoosterWire.begin();
  Serial.println("Enter a string...");

  
}


void loop() {

  while (Serial.available() && !strRcvd) {
  
    char recieved = Serial.read();
    data += recieved; 

    // Process string when new line character is recieved
    if (recieved == '\n'){
      Write_File(data); 
      strRcvd = 1; 
      once = 1;
    }
  
  }

  //lBtn1 = GPIOPinRead(BTN1Port, BTN1);

  if (once == 1) { Read_File(5); once = 0; }


}
