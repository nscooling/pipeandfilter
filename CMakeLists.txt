cmake_minimum_required(VERSION 2.6)

project(executable)

set(CMAKE_CXX_FLAGS "-std=c++14 -DTESTS -DEVENT_WITH_DOCTEST -DPIPE_WITH_DOCTEST -DPIPELINE_WITH_DOCTEST -DGDT_WITH_DOCTEST")
include_directories(src)
include_directories(doctest/doctest)
AUX_SOURCE_DIRECTORY(src SOURCES)

add_executable(executable ${SOURCES})
target_link_libraries(executable pthread)

