#!/bin/bash
task="pathpathpathpath"
grader_name="grader"
g++-15 -std=gnu++20 -Wall -O2 -pipe -static -g -o "${task}" "${grader_name}.cpp" "${task}.cpp"
