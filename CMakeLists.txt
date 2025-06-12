cmake_minimum_required(VERSION 3.9.1)
project(CMakeTutorial)
set(CMAKE_CXX_STANDARD 14)

# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
if(UNIX)
  message("This is a ${CMAKE_SYSTEM_NAME} system")
  add_definitions(-DCMAKEPROVA="Linux")
elseif(WIN32)
  message("This is a Windows System")
  add_definitions(-DCMAKEPROVA="Windows")
endif()

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(CMakeHello src/main.cpp)
