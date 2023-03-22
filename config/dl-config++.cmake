### libconfig++.cmake: CMake file for libconfig++ library
###
### 2023, March 21
### Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
###
### Copyright 2023, Corentin COUTRET-ROZET

set(CONFIGPP_MODULE_URL "https://raw.githubusercontent.com/hyperrealm/libconfig/master/contrib/cmake/cmake_work/FindConfig%2B%2B.cmake")

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/FindConfig++.cmake)
    file(DOWNLOAD ${CONFIGPP_MODULE_URL} ${CMAKE_CURRENT_SOURCE_DIR}/config/FindConfig++.cmake)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/FindConfig++.cmake)
    message(STATUS "Successfully downloaded FindConfig++ module.")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/config)
else()
    message(FATAL_ERROR "Failed to download FindConfig++ module.")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/config)
find_package(Config++ REQUIRED)
