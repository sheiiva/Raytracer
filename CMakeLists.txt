### CMakeLists.txt: RayTracer
###
### 2023, March 20
### Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
###
### Copyright 2023, Corentin COUTRET-ROZET

cmake_minimum_required(VERSION 3.20)

project(
    RayTracer
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/sheiiva/RayTracer"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
include(config/versions.cmake)
# Place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

### SOURCES ###

include(config/dl-config++.cmake)

set(SOURCES
    raytracer/Ray/Ray.cpp
    raytracer/Sphere/Sphere.cpp
    raytracer/Camera/Camera.cpp
)

set(HEADERS
    maths/Maths.hpp
    maths/Vector/Vector.hpp
    raytracer/RayTracer.hpp
    raytracer/Ray/Ray.hpp
    raytracer/Sphere/Sphere.hpp
    raytracer/Camera/Camera.hpp
)

add_executable(${PROJECT_NAME}
    main.cpp
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        maths/Vector
        raytracer/Ray
        raytracer/Sphere
        raytracer/Camera
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        stdc++
        config++
        m
)

### DOCUMENTATION ###

include(docs/doxygen.cmake)

### TESTS ###

enable_testing()

include(config/googletest-config.cmake)

set(T_SOURCES
    maths/Vector/tests/Vector_tests.cpp
    raytracer/Ray/tests/Ray_tests.cpp
    raytracer/Sphere/tests/Sphere_tests.cpp
    raytracer/Camera/tests/Camera_tests.cpp
)

add_executable(${PROJECT_NAME}_tests
    ${SOURCES}
    ${T_SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
        maths/Vector
        raytracer/Ray
        raytracer/Sphere
        raytracer/Camera
)

target_link_libraries(
    ${PROJECT_NAME}_tests
    stdc++
    config++
    m
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)