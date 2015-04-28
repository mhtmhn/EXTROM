#include <Wire.h>
#include <extrom.h>
extrom rom;
//extrom rom0,rom1(0x51)...rom7(0x57);
unsigned long wstarttime, wstoptime, rstoptime;

int a = 0;
void setup() {
  while (!Serial) {}
  Serial.begin(115200);


  wstarttime = millis();
  for (unsigned long i = 0; i < 65536 ; i++)
  {
    a++;
    if (a == 256)
    {
      a = 0;
    }
    rom.writebyte(i, (byte)a);
    Serial.print("Writing:");
    Serial.print(a);
    Serial.print(" at:");
    Serial.println(i);
  }
  wstoptime = millis();
  for (unsigned long i = 0; i < 65536 ; i++)
  {
    Serial.println((int)rom.readbyte(i));
  }
  rstoptime = millis();
  Serial.println("Total Write Time:");
  Serial.println(wstoptime - wstarttime);
  Serial.println("Total Read Time:");
  Serial.println(rstoptime - wstoptime);
}
void loop() {}
