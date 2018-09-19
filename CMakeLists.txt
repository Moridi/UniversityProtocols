cmake_minimum_required(VERSION 2.8)
project(UniversityProtocols)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(asn/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/asn)

file(GLOB LIB_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/asn/*.c)
file(GLOB LIB_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/asn/*.h)

set(INCLUDE_DIR include/)
set(SOURCE_DIR src/)

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB SOURCES
    ${SOURCE_DIR}*.cpp)

file(GLOB HEADERS
    ${INCLUDE_DIR}*.h)

file(GLOB SOURCE_FILES
    ${LIB_SOURCES}
    ${LIB_HEADERS}
    ${HEADERS}
    ${SOURCES})

add_library(main-lib ${SOURCE_FILES})
target_link_libraries(main-lib university-protocols-xer-decoder)

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES})
