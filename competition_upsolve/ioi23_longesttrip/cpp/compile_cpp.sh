#!/bin/bash

problem="longesttrip"
grader_name="grader"

g++-13 -std=gnu++17 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
