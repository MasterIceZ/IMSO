import os
import sys

class ConsoleHandler:
    def send(self, s: str):
        os.system(s)
    

console = ConsoleHandler()

taskName = sys.argv[1]
print(f"Task: { taskName }")

console.send(f"g++ -std=c++14 -Wall grader.cpp { taskName }.cc -o grader")
console.send(".\grader.exe < input.txt")
