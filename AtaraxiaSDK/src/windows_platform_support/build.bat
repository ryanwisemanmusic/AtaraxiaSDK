@echo off

:: Setting Qt environment variables
SET PATH=C:\Qt\5.15.2\minigw81_64\bin;%PATH%
SET QTDIR=C:\Qt\5.15.2\mingw81_64
SET QMAKE=%QTDIR%\bin\qmake

:: MiniGW to make command
SET MAKE=mingw32-make

:: Project Directory
SET PROJECT_DIR=C:\path\we\will\later\add

:: Open Project Directory
cd %PROJECT_DIR%

%QMAKE% -project

:: QMake Makefile conversion
%QMAKE%

:: Build the project
%MAKE%

:: Project launch
start MyQTApp.exe

::Exiting
exit