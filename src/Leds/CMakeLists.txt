project(LEDS)

set(APPLICATION_SOURCE_FILES ${APPLICATION_SOURCE_FILES} ${LEDS_SOURCE_DIR}/src/leds.c PARENT_SCOPE)
set(APPLICATION_HEADER_DIRS ${APPLICATION_HEADER_DIRS} ${LEDS_SOURCE_DIR}/src/ PARENT_SCOPE)

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
	COMMAND ruby ${CMOCK_SCRIPT_DIR}/cmock.rb --mock_path="${MOCKS_SOURCE_DIR}" ${HELLO_SOURCE_DIR}/src/hal/src/hal.h
	DEPENDS ../hal/src/hal.h
)

add_custom_command(
	OUTPUT ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c
	COMMAND ruby ${UNITY_SCRIPT_DIR}/generate_test_runner.rb ${LEDS_SOURCE_DIR}/test/Testleds.c ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c
	DEPENDS ${LEDS_SOURCE_DIR}/test/Testleds.c
)

add_executable(ledtest ${LEDTEST_SOURCE_FILES})

get_target_property(test_binary ledtest LOCATION)
add_custom_target(tester DEPENDS ledtest)
add_custom_command(
    TARGET tester
    #COMMAND ${test_binary}  > ${LEDS_SOURCE_DIR}/test/Testleds.test || true
    COMMAND ${test_binary} > ${LEDS_SOURCE_DIR}/test/Testleds.test && notify-send "Success!"
    DEPENDS ledtest
)


#add_custom_command(
#	OUTPUT ${LEDS_SOURCE_DIR}/test/Testleds.test
#	COMMAND ${LEDS_BINARY_DIR}/ledtest > ${LEDS_SOURCE_DIR}/test/Testleds.test
#	DEPENDS ledtest
#)

add_custom_target(DO_LEDS_MOCK_FILES DEPENDS ${LEDS_MOCK_FILES})
add_custom_target(LEDS_REST_RUNNER DEPENDS ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c )

add_dependencies(ledtest DO_LEDS_MOCK_FILES LEDS_REST_RUNNER)

#add_custom_target(LEDS_TEST_RESULT DEPENDS ${LEDS_SOURCE_DIR}/test/Testleds.test)










