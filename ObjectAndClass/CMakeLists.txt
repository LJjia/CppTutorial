cmake_minimum_required(VERSION 3.13)
project(ObjectAndClass)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-fno-elide-constructors ${CMAKE_CXX_FLAGS}")
aux_source_directory(${PROJECT_SOURCE_DIR}/ SRC_LIST_C)
include_directories(${PROJECT_SOURCE_DIR}/)


add_executable(ObjectAndClass ${SRC_LIST_C})
