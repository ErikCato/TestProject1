#include <stdio.h>
#include "leds.h"

int main(void)
{
	unsigned char led_number = 1;

	printf("LED %d is : ",led_number);

	if (IsLedOn(led_number))
	{
		printf("ON\n");
	}
	else
	{
		printf("OFF\n");
	}


  return 0;
}
