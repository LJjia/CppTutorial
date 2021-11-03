cmake_minimum_required(VERSION 3.13)
project(CodeReuse)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall ${CMAKE_CXX_FLAGS}")
add_definitions("-Wall")
aux_source_directory(${PROJECT_SOURCE_DIR}/ SRC_LIST_C)
include_directories(${PROJECT_SOURCE_DIR}/)


add_executable(CodeReuse ${SRC_LIST_C})