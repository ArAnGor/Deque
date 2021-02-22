cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Deque)
project(${PROJECT_NAME})
  
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(MP2_LIBRARY "${PROJECT_NAME}")

add_subdirectory(Deque)