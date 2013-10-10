/*
 * hal.c
 *
 *  Created on: Oct 8, 2013
 *      Author: ercat1
 */


static int hw_register_a;


void SetRegisterValue(unsigned int value)
{
	hw_register_a = value;
}

unsigned int GetRegisterValue(void)
{
	return hw_register_a;
}
