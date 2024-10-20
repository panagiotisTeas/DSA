@echo off
setlocal

rem Main script logic: handle command-line arguments
if "%1" == "rclean" (
    goto :cleanRelease
) else if "%1" == "clean" (
    goto :cleanDebug
) else if "%1" == "sclean" (
    goto :cleanStrict
) else if "%1" == "rcompile" (
    goto :compileRelease
) else if "%1" == "compile" (
    goto :compileDebug
) else if "%1" == "scompile" (
    goto :compileStrict
) else if "%1" == "rrun" (
    goto :runRelease
) else if "%1" == "run" (
    goto :runDebug
) else if "%1" == "srun" (
    goto :runStrict
) else (
    echo Invalid argument.
    exit /b 1
)

goto :eof

rem Clean for release build
:cleanRelease
    echo Cleaning build file... (release)
    if exist build\release (rmdir /s /q build\release)
    goto :eof

rem Clean for debug build
:cleanDebug
    echo Cleaning build file... (debug)
    if exist build\debug (rmdir /s /q build\debug)
    goto :eof

rem Clean for strict build
:cleanStrict
    echo Cleaning build file... (strict)
    if exist build\strict (rmdir /s /q build\strict)
    goto :eof

rem Compile for release build
:compileRelease
    call :cleanRelease
    echo Compiling... (release)
    if not exist build\release (mkdir build\release)
    g++ -I inc -O2 -std=c++20 main.cpp -o build\release\app.exe
    if errorlevel 1 (
        echo Compilation failed.
        exit /b 1
    )
    goto :eof

rem Compile for debug build
:compileDebug
    call :cleanDebug
    echo Compiling... (debug)
    if not exist build\debug (mkdir build\debug)
    g++ -I inc -Wall -pedantic -g -std=c++20 main.cpp -o build\debug\app.exe
    if errorlevel 1 (
        echo Compilation failed.
        exit /b 1
    )
    goto :eof

rem Compile for strict build
:compileStrict
    call :cleanStrict
    echo Compiling... (strict)
    if not exist build\strict (mkdir build\strict)
    g++ -I inc -std=c++20 -pedantic -Wall -Wextra -Werror -Wshadow -Wsign-conversion -g main.cpp -o build\strict\app.exe
    if errorlevel 1 (
        echo Compilation failed.
        exit /b 1
    )
    goto :eof

rem Run release build
:runRelease
    echo Running... (release)
    if exist build\release\app.exe (
        build\release\app.exe
    ) else (
        echo Executable not found. Compile first.
        exit /b 1
    )
    goto :eof

rem Run debug build
:runDebug
    echo Running... (debug)
    if exist build\debug\app.exe (
        build\debug\app.exe
    ) else (
        echo Executable not found. Compile first.
        exit /b 1
    )
    goto :eof

rem Run strict build
:runStrict
    echo Running... (strict)
    if exist build\strict\app.exe (
        build\strict\app.exe
    ) else (
        echo Executable not found. Compile first.
        exit /b 1
    )
    goto :eof

:end
endlocal
exit /b 0