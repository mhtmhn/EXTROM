#include <Wire.h>
#include <extrom.h>
#include <extrom_anytype.h>//Any type extended functions
extrom rom; //Or extrom rom0; default address is 0x50 when nothing is passed
//extrom rom1(0x51); //Here 0x51 is set as address for object rom1!(A0 pulled to 5V in device)
//Use: extrom rom0,rom1(0x51)...rom7(0x57); to interface upto 8 devices passing I2C device address
struct anytype //Example datatype
{
  int a;
  float b;
  unsigned long c;
} variable1, variable2;

void setup() {
  while (!Serial);//Wait for serial enumeration, Leonardo Only!
  Serial.begin(115200);
  
  //Initialize data
  variable1.a = 1;
  variable1.b = 0.5;
  variable1.c = millis();
  
  //Write data
  Serial.println(F("Writing from Variable1:"));
  //writetype(rom1,0,variable);
  Serial.println(writetype(rom, 0, variable1)); //Syntax: writetype(extrom_object, initial_address, any_datatype);
                                                //returns the starting address for next write operation
  //Read data written
  Serial.println(F("Reading to Variable2:"));
  //readtype(rom1,0,variable);
  Serial.println(readtype(rom, 0, variable2));  //Syntax: readtype(extrom_object, initial_address, datatype_used_in_write)
                                                //returns the starting address for next read operation
  Serial.println(F("Variable1:"));
  Serial.println(variable1.a);
  Serial.println(variable1.b);
  Serial.println(variable1.c);
  Serial.println(F("Variable2:"));
  Serial.println(variable2.a);
  Serial.println(variable2.b);
  Serial.println(variable2.c);
}
void loop() {}
