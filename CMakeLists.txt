### CMakeLists.txt: RayTracer
###
### 2023, March 20
### Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
###
### Copyright 2023, Corentin COUTRET-ROZET

cmake_minimum_required(VERSION 3.14)

project(
    RayTracer
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/sheiiva/RayTracer"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
# Place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set(SOURCES
    raytracer/Ray/Ray.cpp
    raytracer/Sphere/Sphere.cpp
    raytracer/Camera/Camera.cpp
)

set(HEADERS
    maths/Vector/Vector.hpp
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

### TESTS ###

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

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
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)