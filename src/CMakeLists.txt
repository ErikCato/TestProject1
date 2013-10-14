set(APPLICATION_SOURCE_FILES Application.c)

set(UNITY_SRC_DIR ${USER_LIB_SOURCE_DIR}/Unity-master/src)
set(CMOCK_SRC_DIR ${USER_LIB_SOURCE_DIR}/CMock-master/src)

set(UNITY_SCRIPT_DIR ${USER_LIB_SOURCE_DIR}/Unity-master/auto)
set(CMOCK_SCRIPT_DIR ${USER_LIB_SOURCE_DIR}/CMock-master/lib)


add_subdirectory("hal")
add_subdirectory("Leds")
add_subdirectory("mock")


include_directories(${APPLICATION_HEADER_DIRS})

add_executable(hello ${APPLICATION_SOURCE_FILES})

#add_dependencies(hello LEDS_TEST_RESULT)




