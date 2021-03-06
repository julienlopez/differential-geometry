cmake_minimum_required(VERSION 2.8)

project(Cpdifferential-geometry-tests)

set(EXECUTABLE_OUTPUT_PATH ../bin)

ADD_DEFINITIONS(-std=c++11 -g -O0 --coverage -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-declarations -Wredundant-decls -Winline -Wno-long-long -Wuninitialized -Wconversion)
SET(CMAKE_EXE_LINKER_FLAGS "-g -O0 --coverage")

include_directories(../src)

file(GLOB_RECURSE source_files ../src/*)
file(GLOB_RECURSE lst ../src/*)

#removing src/main.cpp
foreach(file ${lst})
if(${file} MATCHES "^.*main.cpp$")
list(REMOVE_ITEM source_files ${file})
endif()
endforeach()

file(GLOB_RECURSE source_files_tests ./*)
list( APPEND source_files_tests ${source_files})

add_executable(tests ${source_files_tests})

target_link_libraries(tests
        gtest
        pthread
)
