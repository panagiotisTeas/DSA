
#if defined(_MSC_VER)
    //* Microsoft Visual C++
    #define debugbreak() __debugbreak()

#elif defined(__GNUC__) || defined(__clang__)
    //* G++/Clang compiler
    #if defined(__i386__) || defined(__x86_84__)
        //* x86/x64 architecture
        #define debugbreak() __asm__("int $3")

    #elif defined(__arm__)  || defined(__aarch64__)
        //* ARM architecture
        #define debugbreak() __asm__("bkpt #0")

    #else
        //* Other architectures
        #include <signal.h>
        #define debugbreak() raise(SIGTRAP)

    #endif

#elif defined(__unix__) || defined(__APPLE__)
    //* POSIX systems (linux/macOS)
    #include <signal.h>
    #define debugbreak() raise(SIGTRAP)

#else
    #define debugbreak() (void(0))

#endif