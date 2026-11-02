@echo off
set task=pathpathpathpath
set grader_name=grader
g++ -std=gnu++20 -Wall -O2 -pipe -static -g -Wl,--stack,134217728 -o "%task%.exe" "%grader_name%.cpp" "%task%.cpp"
