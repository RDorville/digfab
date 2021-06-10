


// I2C Library
#include <Wire.h>

void setup() {
  Serial.begin (9600);
  Serial.println ("I2C scanner. Scanning ...");
  // initialise I2C
  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  Serial.println ("Done.");
}

void loop() {
  // do nothing here
}



