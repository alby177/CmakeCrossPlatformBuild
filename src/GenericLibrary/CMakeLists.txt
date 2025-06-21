set(LIBRARY_NAME GenericLibrary)

add_library(${LIBRARY_NAME} SHARED GenericLibrary.cpp)

target_compile_definitions(${LIBRARY_NAME} PRIVATE "COMPILE_LIB")