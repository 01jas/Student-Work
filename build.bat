@echo off
set PATH=%cd%\mingw32\bin;%PATH%
del exercise.exe /Q
g++ -std=c++14 -Wall -Wextra -O2 exercise.cpp -o exercise && exercise
PAUSE