cmake_minimum_required(VERSION 2.8)
project(Rectangle)

add_subdirectory(asn/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/asn)

file(GLOB LIB_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/asn/*.c)
file(GLOB LIB_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/asn/*.h)

file(GLOB SOURCE_FILES
    "main.cpp"
    ${LIB_SOURCES}
    ${LIB_HEADERS})

add_library(main-lib ${SOURCE_FILES})
target_link_libraries(main-lib university-protocols-xer-decoder)

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES})
