@echo off
REM ============================================================
REM  build.bat — one‑shot builder for PlatformGame (Conan + CMake)
REM  Usage:  build [Debug|Release]      (default is Debug)
REM ============================================================

REM --- 0.  Parse configuration argument ----------------------
set CONFIG=%1
if "%CONFIG%"=="" set CONFIG=Debug

if /I NOT "%CONFIG%"=="Debug" if /I NOT "%CONFIG%"=="Release" (
    echo Invalid configuration "%CONFIG%". Use Debug or Release.
    exit /b 1
)

REM --- 1.  Establish project & build directories -------------
REM Push to the directory where this script lives so we can run
REM it from anywhere.
pushd "%~dp0"
set BUILD_DIR=build

echo.
echo ===============================
echo   Building %CONFIG% configuration
echo ===============================

REM --- 2.  Clean build folder --------------------------------
if exist "%BUILD_DIR%" (
    echo Removing previous %BUILD_DIR% ...
    rmdir /s /q "%BUILD_DIR%"
)
mkdir "%BUILD_DIR%"

REM --- 3.  Conan install -------------------------------------
echo.
echo === Conan install (%CONFIG%) ===
conan install . -of "%BUILD_DIR%" --build=missing -s build_type=%CONFIG%
if errorlevel 1 (
    echo Conan install failed. Aborting.
    popd
    exit /b %errorlevel%
)

REM --- 4.  CMake configure ----------------------------------
echo.
echo === Configuring CMake ===
cmake -B "%BUILD_DIR%" -S . ^
      -G "Visual Studio 17 2022" ^
      -DCMAKE_TOOLCHAIN_FILE="%cd%\%BUILD_DIR%\conan_toolchain.cmake"
if errorlevel 1 (
    echo CMake configure failed. Aborting.
    popd
    exit /b %errorlevel%
)

REM --- 5.  Build --------------------------------------------
echo.
echo === Building project ===
cmake --build "%BUILD_DIR%" --config %CONFIG%
if errorlevel 1 (
    echo Build failed. Aborting.
    popd
    exit /b %errorlevel%
)

REM --- 6.  Success message ----------------------------------
echo.
echo Build succeeded!
echo Executable: %BUILD_DIR%\%CONFIG%\PlatformGame.exe
echo.

popd
endlocal
