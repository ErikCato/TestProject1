/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "Mockhal.h"

typedef struct _CMOCK_SetRegisterValue_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  unsigned int Expected_value;

} CMOCK_SetRegisterValue_CALL_INSTANCE;

typedef struct _CMOCK_GetRegisterValue_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  unsigned int ReturnVal;

} CMOCK_GetRegisterValue_CALL_INSTANCE;

static struct MockhalInstance
{
  CMOCK_MEM_INDEX_TYPE SetRegisterValue_CallInstance;
  CMOCK_MEM_INDEX_TYPE GetRegisterValue_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mockhal_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.SetRegisterValue_CallInstance, cmock_line, "Function 'SetRegisterValue' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.GetRegisterValue_CallInstance, cmock_line, "Function 'GetRegisterValue' called less times than expected.");
}

void Mockhal_Init(void)
{
  Mockhal_Destroy();
}

void Mockhal_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void SetRegisterValue(unsigned int value)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_SetRegisterValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_SetRegisterValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.SetRegisterValue_CallInstance);
  Mock.SetRegisterValue_CallInstance = CMock_Guts_MemNext(Mock.SetRegisterValue_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'SetRegisterValue' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_TEST_ASSERT_EQUAL_HEX32(cmock_call_instance->Expected_value, value, cmock_line, "Function 'SetRegisterValue' called with unexpected value for argument 'value'.");
  }
}

void CMockExpectParameters_SetRegisterValue(CMOCK_SetRegisterValue_CALL_INSTANCE* cmock_call_instance, unsigned int value)
{
  cmock_call_instance->Expected_value = value;
}

void SetRegisterValue_CMockExpect(UNITY_LINE_TYPE cmock_line, unsigned int value)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_SetRegisterValue_CALL_INSTANCE));
  CMOCK_SetRegisterValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_SetRegisterValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.SetRegisterValue_CallInstance = CMock_Guts_MemChain(Mock.SetRegisterValue_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_SetRegisterValue(cmock_call_instance, value);
}

unsigned int GetRegisterValue(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_GetRegisterValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_GetRegisterValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.GetRegisterValue_CallInstance);
  Mock.GetRegisterValue_CallInstance = CMock_Guts_MemNext(Mock.GetRegisterValue_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'GetRegisterValue' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  return cmock_call_instance->ReturnVal;
}

void GetRegisterValue_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, unsigned int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_GetRegisterValue_CALL_INSTANCE));
  CMOCK_GetRegisterValue_CALL_INSTANCE* cmock_call_instance = (CMOCK_GetRegisterValue_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.GetRegisterValue_CallInstance = CMock_Guts_MemChain(Mock.GetRegisterValue_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

