#include "unity.h"
#include "leds.h"
#include "Mockhal.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_leds_IsLedOn(void)
{
	GetRegisterValue_ExpectAndReturn(0);
	TEST_ASSERT_EQUAL(0,IsLedOn(1));
}

void test_leds_TurnOnLed_2(void)
{
	GetRegisterValue_ExpectAndReturn(0);
	SetRegisterValue_Expect(1 << 3);

	TEST_ASSERT_EQUAL(1,TurnOnLed(2));
}

void test_leds_TurnOnLed_16(void)
{
	TEST_ASSERT_EQUAL(1,TurnOnLed(16));
}

