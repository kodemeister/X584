@echo off

set PATH=C:\Program Files (x86)\Inno Setup 6

:check_win32
if exist "..\Win32\Release\X584.exe" goto :win32
goto :check_win64

:win32
echo Building installer for X584 x86 version...
ISCC /DX584_PLATFORM=Win32 x584.iss

:check_win64
if exist "..\Win64\Release\X584.exe" goto :win64
goto :check_win64x

:win64
echo Building installer for X584 x64 old platform version...
ISCC /DX584_PLATFORM=Win64 x584.iss

:check_win64x
if exist "..\Win64x\Release\X584.exe" goto :win64x
goto :exit

:win64
echo Building installer for X584 x64 version...
ISCC /DX584_PLATFORM=Win64x x584.iss

:exit
echo Press any key to continue...
pause > nul
