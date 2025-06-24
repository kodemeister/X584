@echo off

set "PATH=%PROGRAMFILES(x86)%\HTML Help Workshop;%PATH%"

cd /D "%~dp0"

rem ВНИМАНИЕ: hhc возвращает 1 при успешном завершении и 0 при ошибке.
hhc "X584.hhp"
if not errorlevel 1 exit /B 1

move /Y "X584.chm" "%~1"
if errorlevel 1 exit /B 1

exit /B 0
