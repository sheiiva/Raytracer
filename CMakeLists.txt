cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCES
    maths/Vector/tests/Vector_tests.cpp
    raytracer/Ray/tests/Ray_tests.cpp
    raytracer/Ray/Ray.cpp
)

set(HEADERS
    maths/Vector/Vector.hpp
    raytracer/Ray/Ray.hpp
)

add_executable(
    tests
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(tests
    PRIVATE
        maths/Vector
        raytracer/Ray
)

target_link_libraries(
    tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)