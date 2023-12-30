cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

project("Simulation of company work")

set (HEADERS_PATH ${CMAKE_SOURCE_DIR}/headers)

set (SRC_PATH ${CMAKE_SOURCE_DIR}/src)

set (
    HEADERS_FILE ${CMAKE_SOURCE_DIR}/headers/Company.h 
    ${HEADERS_PATH}/Head.h ${HEADERS_PATH}/Human.h 
    ${HEADERS_PATH}/Manager.h ${HEADERS_PATH}/Worker.h
    ${HEADERS_PATH}/Teams.h
)

set (
    SRC_FILE ${SRC_PATH}/main.cpp ${SRC_PATH}/Company.cpp 
    ${SRC_PATH}/Head.cpp ${SRC_PATH}/Human.cpp ${SRC_PATH}/Manager.cpp 
    ${SRC_PATH}/Worker.cpp ${SRC_PATH}/Teams.cpp
)

add_executable(run ${SRC_FILE} ${HEADERS_FILE})

include_directories("headers/")
include_directories("src/")