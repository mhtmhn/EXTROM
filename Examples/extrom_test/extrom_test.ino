#include <Wire.h>
#include <extrom.h>
extrom rom; //Or extrom rom0; default address is 0x50 when nothing is passed
//extrom rom1(0x51); //Here 0x51 is set as address for object rom1!(A0 pulled to 5V in device)
//Use: extrom rom0,rom1(0x51)...rom7(0x57); to interface upto 8 devices passing I2C device address
unsigned long wstarttime, wstoptime, rstoptime;//Timing variables
int a;//Random data variable

void setup() {
  while (!Serial);//Wait for serial enumeration, Leonardo Only!
  Serial.begin(115200);

  //Write random data
  wstarttime = millis();
  for (unsigned long i = 0; i < 65536 ; i++)//For 64KB EEPROM (24LC512k) 0x0000 to 0xFFFF
  {
    a=random(0,255);
    rom.writebyte(i, (byte)a);
    //rom1.writebyte(i, (byte)a);
    Serial.print("Writing:");
    Serial.print(a);
    Serial.print(" at address:");
    Serial.println(i);
  }
  wstoptime = millis();
  
  //Read data written
  for (unsigned long i = 0; i < 65536 ; i++)//For 64KB EEPROM (24LC512k) 0x0000 to 0xFFFF
  {
    Serial.print("Read:");
    Serial.print((int)rom.readbyte(i));
    //Serial.print((int)rom1.readbyte(i));
    Serial.print(" at address:");
    Serial.println(i);

  }
  rstoptime = millis();
  
  Serial.println("Total Write Time:");
  Serial.println(wstoptime - wstarttime);
  Serial.println("Total Read Time:");
  Serial.println(rstoptime - wstoptime);
}
void loop() {}
