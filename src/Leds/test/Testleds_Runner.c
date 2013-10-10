/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "leds.h"
#include "Mockhal.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_leds_IsLedOn(void);
extern void test_leds_TurnOnLed_2(void);
extern void test_leds_TurnOnLed_16(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  Mockhal_Init();
}
static void CMock_Verify(void)
{
  Mockhal_Verify();
}
static void CMock_Destroy(void)
{
  Mockhal_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "Testleds.c";
  UnityBegin();
  RUN_TEST(test_leds_IsLedOn, 13);
  RUN_TEST(test_leds_TurnOnLed_2, 19);
  RUN_TEST(test_leds_TurnOnLed_16, 27);

  return (UnityEnd());
}