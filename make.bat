@ECHO OFF

SET PATH=%PATH%;C:\Data\MinGW\bin

:Make

gcc -std=c++0x main.cc -lstdc++ -o main.exe

IF NOT X%1==Xrun GOTO End

main.exe

:End