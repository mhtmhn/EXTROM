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
#ifndef _EXTROM_ANYTYPE_H
#define _EXTROM_ANYTYPE_H
template <class extrom_anydatatype> unsigned long writetype(extrom obj,unsigned long address, const extrom_anydatatype& data)
{
    const byte* byte_converted_data = (const byte*)(const void*)&data;
    unsigned long i;
    for (i = 0; i < sizeof(data); i++)
	{
          obj.writebyte(address++, *byte_converted_data++);
	}
    return address;
}

template <class extrom_anydatatype> unsigned long readtype(extrom obj,unsigned long address, extrom_anydatatype& data)
{
    byte* byte_converted_data = (byte*)(void*)&data;
    unsigned long i;
    for (i = 0; i < sizeof(data); i++)
	{
          *byte_converted_data++ = obj.readbyte(address++);
	}
    return address;
}
#endif