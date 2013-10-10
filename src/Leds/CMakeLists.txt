project(LEDS)

set(LEDTEST_SOURCE_FILES
    ${LEDS_SOURCE_DIR}/test/Testleds_Runner.c 
    ${LEDS_SOURCE_DIR}/test/Testleds.c 
    ${LEDS_SOURCE_DIR}/src/leds.c
    ${HELLO_SOURCE_DIR}/lib/Unity-master/src/unity.c
    ${HELLO_SOURCE_DIR}/lib/CMock-master/src/cmock.c
    ${MOCKS_SOURCE_DIR}/Mockhal.c
)

set(LEDTEST_HEADER_DIR
    ${HELLO_SOURCE_DIR}/src/Leds/src
    ${HELLO_SOURCE_DIR}/src/hal/src
    ${MOCKS_SOURCE_DIR}
    ${HELLO_SOURCE_DIR}/lib/Unity-master/src/
    ${HELLO_SOURCE_DIR}/lib/CMock-master/src
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

add_executable(LEDTEST ${LEDTEST_SOURCE_FILES})

add_custom_target(do_trofiles DEPENDS ${LEDS_MOCK_FILES})
add_dependencies(LEDTEST do_trofiles)






