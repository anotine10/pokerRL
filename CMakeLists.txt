# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." ON) # Makes boolean 'test' available.

# Project's name
project(pokerRL)


################################
# Principal Path
################################

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../../generated)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

################################
# GFlag
################################

find_package(gflags REQUIRED)

################################
# GLog
################################
  
find_package (glog 0.3.5 REQUIRED)


################################
# pokerRL
################################


# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")



add_executable(pokerRL src/main.cpp)
target_link_libraries (pokerRL glog::glog)

################################
# Test
################################


if (test)
  if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
  endif (APPLE)

  # GTest
  ADD_SUBDIRECTORY (lib/googletest/googletest)
  
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  # Unit Tests
  # Add test cpp file
  add_executable( runUnitTests test/testgtest.cpp )
  # Link test executable against gtest & gtest_main
  target_link_libraries(runUnitTests gtest gtest_main)
  add_test( runUnitTests runUnitTests )
endif ()