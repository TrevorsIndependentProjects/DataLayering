# Project: Shopping Cart Challenge
#
# Root level CMakeList.txt file

cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(ShoppingCartChallenge)

# Disallow in-source build
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
  message(FATAL_ERROR "This project requires an out-of-source build. Run CMake in a different directory.")
endif()

# Allow CMake to organize targets into folders when creating IDE solution(s)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(PROJECT_TESTING_ENABLED ON)

add_subdirectory(Libraries)
#add_subdirectory(Applications)