cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(lnetd)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(CheckFunctionExists)

if (NOT UNIX)
  message( SEND_ERROR "FAIL: lnetd works only on Unix-like systems" )
endif (NOT UNIX)

check_function_exists(epoll_create
  HAVE_EPOLL)
check_function_exists(kqueue
  HAVE_KQUEUE)

include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/src/config)

add_executable(lnetd src/lnetd.cc
  src/config/config.cc)
include(cpp)
