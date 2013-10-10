project(LEDS)

set(LEDTEST_SOURCE_FILES
    ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c 
    ${LEDS_SOURCE_DIR}/test/Testleds.c 
    ${LEDS_SOURCE_DIR}/src/leds.c
    ${UNITY_SRC_DIR}/unity.c
    ${CMOCK_SRC_DIR}/cmock.c
    ${MOCKS_SOURCE_DIR}/Mockhal.c
)

set(LEDTEST_HEADER_DIR
    ${LEDS_SOURCE_DIR}/src
    ${HELLO_SOURCE_DIR}/src/hal/src
    ${MOCKS_SOURCE_DIR}
    ${UNITY_SRC_DIR}
    ${CMOCK_SRC_DIR}
)

include_directories(${LEDTEST_HEADER_DIR})


set(LEDS_MOCK_FILES  
	${MOCKS_SOURCE_DIR}/Mockhal.c
	${MOCKS_SOURCE_DIR}/Mockhal.h
)

add_custom_command(
	OUTPUT ${LEDS_MOCK_FILES}
	COMMAND ruby  ${HELLO_SOURCE_DIR}/lib/CMock-master/lib/cmock.rb --mock_path="${MOCKS_SOURCE_DIR}" ../hal/src/hal.h
	DEPENDS ../hal/src/hal.h
)

#ruby ../../lib/Unity-master/auto/generate_test_runner.rb test/Testleds.c test/Testleds_Runner.c

add_custom_command(
	OUTPUT ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c
	COMMAND ruby  ${HELLO_SOURCE_DIR}/lib/Unity-master/auto/generate_test_runner.rb  test/Testleds.c test/Testleds_Runner.c
	DEPENDS ${LEDS_SOURCE_DIR}/test/Testleds.c
)

add_executable(LEDTEST ${LEDTEST_SOURCE_FILES})

add_custom_target(DO_LEDS_MOCK_FILES DEPENDS ${LEDS_MOCK_FILES})
add_custom_target(LEDS_REST_RUNNER DEPENDS ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c )

add_dependencies(LEDTEST DO_LEDS_MOCK_FILES LEDS_REST_RUNNER)






