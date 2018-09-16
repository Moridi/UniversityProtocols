cmake_minimum_required(VERSION 2.6)

find_program(ASN1_COMPILER
	NAMES asn1c
	DOC "Abstract Syntax Notation Compiler")

if(NOT ASN1_COMPILER)
	message(FATAL_ERROR "Asn1c not found!\nTry \"sudo apt-get install asn1c\"")
endif()

set(INPUT_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/UniversityProtocols.asn)

set(ASN1C_FLAGS -fskeletons-copy -fcompound-names)

execute_process(COMMAND ${ASN1_COMPILER} ${ASN1C_FLAGS} ${INPUT_FILES}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	OUTPUT_VARIABLE OUT_VAR
	ERROR_VARIABLE ERR_VAR)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Remove useless files.
execute_process(COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/converter-sample.c)

# Create Library
file(GLOB LIB_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/*.c)
file(GLOB LIB_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/*.h)

add_library(university-protocols-xer-decoder STATIC ${LIB_SOURCES} ${LIB_HEADERS})
