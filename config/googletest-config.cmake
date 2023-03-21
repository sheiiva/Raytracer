### googletest-config.cmake: CMake configuration file for googletest
###
### 2023, March 21
### Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
###
### Copyright 2023, Corentin COUTRET-ROZET

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        ${GTEST_VERSION}
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)