cmake_minimum_required(VERSION 3.10)
project(CMakeTutorial)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME CMakeHello)
set(LIBRARY_NAME GenericLibrary)
set(SOURCE_DIR src)
set(BIN_DIR bin)

# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
# On a mac both APPLE and UNIX are defined
if(APPLE)
  message("Finally got a ${CMAKE_SYSTEM_NAME} system")
  add_definitions(-DCMAKEPROVA="${CMAKE_SYSTEM_NAME}")
elseif(UNIX)
  message("This is a ${CMAKE_SYSTEM_NAME} system")
  add_definitions(-DCMAKEPROVA="${CMAKE_SYSTEM_NAME}")
elseif(WIN32)
  message("This is a Windows System")
  add_definitions(-DCMAKEPROVA="Windows")
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE_NAME})
endif()

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${BIN_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/${BIN_DIR})

add_executable(${EXECUTABLE_NAME} ${SOURCE_DIR}/main.cpp)

add_subdirectory(${SOURCE_DIR}/${LIBRARY_NAME})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
target_include_directories(${EXECUTABLE_NAME} PUBLIC "${PROJECT_BINARY_DIR}" "${LIBRARY_NAME}")


