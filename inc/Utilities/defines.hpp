#define DEBUG

#if defined(_WIN32)
    #include <windows.h>
    #define SIGTRAP SIGINT
    #define winDebugBreak() DebugBreak()

#else
    #define winDebugBreak()

#endif