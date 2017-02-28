cmake_minimum_required(VERSION 2.6)

project(executable)

set(CMAKE_CXX_FLAGS "-std=c++14 -D TESTS -D PIPELINE_WITH_DOCTEST -D GDT_WITH_DOCTEST")
include_directories(src)
include_directories(doctest/doctest)
AUX_SOURCE_DIRECTORY(src SOURCES)

add_executable(executable ${SOURCES})
target_link_libraries(executable pthread)

