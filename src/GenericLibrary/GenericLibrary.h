#ifndef GENERICLIBRARY_H
#define GENERICLIBRARY_H

#if defined(_MSC_VER)
    //  Microsoft 
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#else
    //  do nothing and hope for the best?
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#if COMPILE_LIB
#   define GENERIC_LIBRARY_PUBLIC EXPORT
#else
#   define GENERIC_LIBRARY_PUBLIC IMPORT
#endif

GENERIC_LIBRARY_PUBLIC int AddNumbers(int first, int second);

#endif