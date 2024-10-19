#!/bin/bash

clean()
{
    if [ $1 -eq 0 ]; then
        echo "Cleaning build file... (release)"
        rm -r build/release
    elif [ $1 -eq 1 ]; then
        echo "Cleaning build file... (debug)"
        rm -r build/debug
    elif [ $1 -eq 2 ]; then
        echo "Cleaning build file... (strict)"
        rm -r build/strict
    else
        echo "Something went wrong with clean."
    fi
}

compile()
{
    if [ $1 -eq 0 ]; then
        echo "Compiling... (release)"
        mkdir -p build/release
        g++ -I /$(pwd)/inc -O2 -std=c++20 main.cpp -o build/release/app
    elif [ $1 -eq 1 ]; then
        echo "Compiling... (debug)"
        mkdir -p build/debug
        g++ -I /$(pwd)/inc -Wall -pedantic -g --std=c++20 main.cpp -o build/debug/app
    elif [ $1 -eq 2 ]; then
        echo "Compiling... (strict)"
        mkdir -p build/strict
        g++ -I /$(pwd)/inc -std=c++20 -pedantic -Wall -Wextra -Werror -Wshadow -Wsign-conversion -g main.cpp -o build/strict/app
    else
        echo "Something went wrong with compile."
    fi
}

run()
{
    if [ $1 -eq 0 ]; then
        echo "Running... (release)"
        ./build/release/app
    elif [ $1 -eq 1 ]; then
        echo "Running... (debug)"
        ./build/debug/app
    elif [ $1 -eq 2 ]; then
        echo "Running... (strict)"
        ./build/strict/app
    else
        echo "Something went wrong with run."
    fi
}

if [ $1 = "rclean" ]; then
    clean 0
elif [ $1 = "clean" ]; then
    clean 1
elif [ $1 = "sclean" ]; then
    clean 2
elif [ $1 = "rcompile" ]; then
    clean 0
    compile 0
elif [ $1 = "compile" ]; then
    clean 1
    compile 1
elif [ $1 = "scompile" ]; then
    clean 2
    compile 2
elif [ $1 = "rrun" ]; then
    run 0
elif [ $1 = "run" ]; then
    run 1
elif [ $1 = "srun" ]; then
    run 2
else
    echo "Argument is not recognized!"
fi

# -Wall: show all warnings
# -g: for debugging (when you want to use gdb and valgrind)
# --std=c++xx: C++ standard to use
# -o: executable name output
# -I: directories to include ($(pwd) == print working directory)
# -Werror: makes warnings into errors
# -pedantic: ICO C++ rules
# -Wextra: extra warnings not enabled by -Wall
# -Wfatal-errors: make warnings into fatal erros
# -Wsign-conversion: for unsafe conversions
# -Ox: makes optimazitions (0: not opt -> 3: full opt) (there's also -fast)