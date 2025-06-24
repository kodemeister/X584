@echo off

set "PATH=%PROGRAMFILES(x86)%\Inno Setup 6;%PATH%"

cd /D "%~dp0"

if exist "..\Win32\Release\X584.exe" (
  echo Building installer for X584 ^(Windows 32-bit, Release^)...
  ISCC /DX584_PLATFORM=Win32 /DX584_CONFIGURATION=Release "X584.iss"
  if errorlevel 1 (
    pause
    exit /B 1
  )
) else (
  echo X584 ^(Windows 32-bit, Release^) is not found - skipping installer build
)

if exist "..\Win64\Release\X584.exe" (
  echo Building installer for X584 ^(Windows 64-bit, Release^)...
  ISCC /DX584_PLATFORM=Win64 /DX584_CONFIGURATION=Release "X584.iss"
  if errorlevel 1 (
    pause
    exit /B 1
  )
) else (
  echo X584 ^(Windows 64-bit, Release^) is not found - skipping installer build
)

if exist "..\Win64x\Release\X584.exe" (
  echo Building installer for X584 ^(Windows 64-bit ^(Modern^), Release^)...
  ISCC /DX584_PLATFORM=Win64x /DX584_CONFIGURATION=Release "X584.iss"
  if errorlevel 1 (
    pause
    exit /B 1
  )
) else (
  echo X584 ^(Windows 64-bit ^(Modern^), Release^) is not found - skipping installer build
)

pause
exit /B 0
