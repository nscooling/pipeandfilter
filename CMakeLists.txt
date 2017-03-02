cmake_minimum_required(VERSION 2.8.12)

project(executable CXX)

#set(CMAKE_CXX_FLAGS " -std=c++14 -DTESTS ")
add_compile_options(-std=c++14)
add_compile_options(-DTESTS)
add_compile_options(-DEVENT_WITH_DOCTEST)

add_compile_options(-DPIPE_WITH_DOCTEST)
add_compile_options(-DPIPELINE_WITH_DOCTEST)
add_compile_options(-DIFILTER_WITH_DOCTEST)
#add_compile_options(-DGDT_WITH_DOCTEST)

add_compile_options(-DBUFFER_WITH_DOCTEST)
add_compile_options(-DEVENTBUFFER_WITH_DOCTEST)
add_compile_options(-DIDFILTER_WITH_DOCTEST)


include_directories(src)
include_directories(doctest/doctest)
AUX_SOURCE_DIRECTORY(src SOURCES)

add_executable(executable ${SOURCES})
target_link_libraries(executable pthread)

