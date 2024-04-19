cmake_minimum_required(VERSION 3.5)

project(DP_03_03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS_LIST
    logmessage.h
    type.h
    messageprocessor.h
    fatalerrorprocessor.h
    errorprocessor.h
    warningprocessor.h
    unknownmessageprocessor.h
    settings.h
    )
set(SRC_LIST
    messageprocessor.cpp
    fatalerrorprocessor.cpp
    errorprocessor.cpp
    warningprocessor.cpp
    unknownmessageprocessor.cpp
    )

add_executable(${PROJECT_NAME} main.cpp ${HEADERS_LIST} ${SRC_LIST})
