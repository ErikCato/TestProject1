#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#Name your project here
project(HELLO)
enable_testing()


add_subdirectory(src)
add_subdirectory(lib)

set_target_properties(gtest
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${gtest_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${gtest_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${gtest_SOURCE_DIR}"
    CMAKE_BUILD_TYPE "Release"
    
)

set_target_properties(gtest_main
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${gtest_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${gtest_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${gtest_SOURCE_DIR}"
    CMAKE_BUILD_TYPE "Release"
    
)

set_target_properties(gmock
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${gmock_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${gmock_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${gmock_SOURCE_DIR}"
    CMAKE_BUILD_TYPE "Release"
    
)

set_target_properties(gmock_main
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${gmock_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${gmock_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${gmock_SOURCE_DIR}"
    CMAKE_BUILD_TYPE "Release"
)


