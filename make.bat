@echo off
mkdir build
g++ -I.\include\ -o build\encoder.exe win\encoder.cpp
g++ -I.\include\ -o build\decoder.exe win\decoder.cpp
g++ -I.\include\ -o build\key.exe win\key.cpp
xcopy win\dlls\* build\ /S /Y
