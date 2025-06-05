@echo off

set PATH=%PROGRAMFILES(x86)%\Inno Setup 6;%PATH%

if exist "..\Win32\Release\X584.exe" (
	echo Building installer for X584 x86 version...
	ISCC /DX584_PLATFORM=Win32 x584.iss
)

if exist "..\Win64\Release\X584.exe" (
	echo Building installer for X584 x64 old platform version...
	ISCC /DX584_PLATFORM=Win64 x584.iss
)

if exist "..\Win64x\Release\X584.exe" (
	echo Building installer for X584 x64 version...
	ISCC /DX584_PLATFORM=Win64x x584.iss
)

echo Press any key to continue...
pause > nul
