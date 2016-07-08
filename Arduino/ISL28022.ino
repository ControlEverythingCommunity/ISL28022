// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ISL28022
// This code is designed to work with the ISL28022_I2CS I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include <Wire.h>

// I2C address of the ISL28022, 0x40(64)
#define Addr 0x40

void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise Serial Communication, set baud rate = 9600
  Serial.begin(9600);
  
  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select configuration register
  Wire.write(0x00)
  // No reset, Bus voltage range = 60V, PGA (Shunt voltage only) = +/- 320mV
  // Bus & shunt ADC resolution = 15-bit, Shunt, bus & continuous mode
  Wire.write(0x79);
  Wire.write(0x9F);
  // End I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{
  byte data[2];

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select shunt voltage register
  Wire.write(0x01);
  // Stop I2C Transmission
  Wire.endTransmission();
  delay(300);

  // Request 2 bytes of data
  Wire.requestFrom(Addr, 2);

  // Read 2 bytes of data
  // raw_shunt msb, raw_shunt lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  // Convert the data
  int raw_shunt = data[0] * 256 + data[1];
  if (raw_shunt > 32767)
  {
    raw_shunt -= 65536;
  }
  
  // Output data to serial monitor
  Serial.print("Raw Value of Shunt Voltage : ");
  Serial.println(raw_shunt);
  delay(500);
}
