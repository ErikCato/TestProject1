#include "hal.h"


unsigned char IsLedOn(unsigned char led_number)
{
	if (GetRegisterValue() & (1 << led_number))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


unsigned char TurnOnLed(unsigned char led_number)
{
	if (led_number < 16)
	{
		unsigned int bit_pattern = GetRegisterValue();
		SetRegisterValue(bit_pattern |= 1 << led_number);
		return 1;
	}
	else
	{
		return 0;
	}
}

