/*
	----------------------------------------
	https://github.com/sinisterdev/GCRA_MKI
	----------------------------------------
	S1N1S73RDevelopers-04/28/2015
	I invest time and resources providing 
	this open source code, Please provide 
	proper citations if you plan use it in 
	any of your projects. It may benefit 
	someone else as it did to you!
	----------------------------------------
*/
#include<extrom.h>

extrom::extrom(void)
{
	Wire.begin();
	TWBR = 24;
	dev_address=0x50;
}
	
extrom::extrom(byte dev_add)
{
	Wire.begin();
	TWBR = 24;
	dev_address=dev_add;
}

byte extrom::readbyte(unsigned long address)
{
    Wire.beginTransmission(dev_address);
    Wire.write((byte)((address) >> 8));
    Wire.write((byte)address);
    Wire.endTransmission();
    delay(5);
    Wire.requestFrom(dev_address, sizeof(byte)); 
	return ((byte)Wire.read());	
}

boolean extrom::writebyte(unsigned long address, byte data)
{
    Wire.beginTransmission(dev_address);
    Wire.write((byte)((address) >> 8));
    Wire.write((byte)address);
    Wire.write(data);
    Wire.endTransmission();
	delay(5);
	return(true);
}