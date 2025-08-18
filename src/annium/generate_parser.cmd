@echo off
SETLOCAL

REM *************SETUP
REM SET MSYS_HOME=
REM *************SETUP END

SET PATH=%PATH%;%MSYS_HOME%\usr\bin

flex --nounistd annium.l
bison.exe -d -v -Wother -Wcounterexamples --output=annium.tab.cpp annium.y
echo done
ENDLOCAL
