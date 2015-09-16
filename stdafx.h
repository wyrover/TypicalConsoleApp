// We must do it strictly!!!
#define STRICT 1

// the target versioning header
#include "targetver.h"

#ifdef _MSC_VER
    // for detecting memory leak (MSVC only)
    #define _CRTDBG_MAP_ALLOC
    #include <crtdbg.h>
#endif

// C runtime headers
#include <cstdlib>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
    #include <tchar.h>
#endif

// C++ headers
#include <string>
#include <vector>
#include <new>

// Windows headers
//#include <windows.h>

// private headers
#include "TypicalConsoleApp.h"

#ifdef _MSC_VER
    // for detecting memory leak (MSVC only)
    #define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
