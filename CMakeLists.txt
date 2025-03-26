cmake_minimum_required(VERSION 3.31)

set(This GameHouseProject)

project(${This} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")
file(GLOB INLS "src/*.inl")
add_library(${This} STATIC ${HEADERS} ${SOURCES} ${INLS})

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)
