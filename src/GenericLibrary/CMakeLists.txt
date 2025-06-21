add_library(${LIBRARY_NAME} SHARED GenericLibrary.cpp)

target_compile_definitions(${LIBRARY_NAME} PRIVATE "COMPILE_LIB")

target_include_directories(${LIBRARY_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} PUBLIC tutorial_compiler_flags)