/*
	----------------------------------------
	https://github.com/sinisterdev/
	----------------------------------------
	S1N1S73RDevelopers-04/28/2015
	I invest time and resources providing 
	this open source code, Please provide 
	proper citations if you plan use it in 
	any of your projects. It may benefit 
	someone else as it did to you!
	----------------------------------------
*/
#ifndef _EXTROM_H
#define _EXTROM_H
#include<Arduino.h>
#include<Wire.h>
class extrom
{
	private:
	byte dev_address;
	
	public:
	extrom(void);
	extrom(byte);
	byte readbyte(unsigned long);
	boolean writebyte(unsigned long, byte);
};
#endif