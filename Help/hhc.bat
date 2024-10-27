@echo off

rem Этот скрипт исправляет код возврата компилятора hhc на противоположный.
rem hhc возвращает 1 при успешном завершении и 0 при ошибке, хотя приложения
rem должны наоборот возвращать 0 при успехе и ненулевое значение при ошибке.

set PATH=%PATH%;C:\Program Files (x86)\HTML Help Workshop

hhc.exe %1

if %ERRORLEVEL% equ 0 exit /B 1
if %ERRORLEVEL% equ 1 exit /B 0
