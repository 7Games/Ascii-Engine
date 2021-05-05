@echo off

title Epic Builder 3000
color 0f

echo Building...
g++ -o ./bin/a.exe *.cpp *.hpp
color 0a
echo Build Finished!
color 0f
pause