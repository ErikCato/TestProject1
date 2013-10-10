set(APPLICATION_SOURCE_FILES Application.c)

set(UNITY_SRC_DIR ${USER_LIB_SOURCE_DIR}/Unity-master/src)
set(CMOCK_SRC_DIR ${USER_LIB_SOURCE_DIR}/CMock-master/src)

set(UNITY_SCRIPT_DIR ${USER_LIB_SOURCE_DIR}/Unity-master/auto)
set(CMOCK_SCRIPT_DIR ${USER_LIB_SOURCE_DIR}/CMock-master/lib)


add_subdirectory("hal")
add_subdirectory("Leds")
add_subdirectory("mock")

#add_executable(hello ${hello_source_files})




