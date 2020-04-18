cmake_minimum_required(VERSION 3.6)
project(CalculatorTests)

set(CMAKE_CXX_STANDARD 11)

# Download and unpack googletest (while configuring)
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
        )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
        )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest to build
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build"
        )

if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include"
            )
endif()

include_directories(cmake-build-debug/googletest-src/googlemock/include)
include_directories(cmake-build-debug/googletest-src/googletest/include)

set(SOURCE_FILES CalculatorTests.cpp ../lib.h ../lib.cpp)
add_executable(CalculatorTests ${SOURCE_FILES})

add_library(math SHARED ../lib.cpp ../lib.h)

target_link_libraries(CalculatorTests math gtest gtest_main)
