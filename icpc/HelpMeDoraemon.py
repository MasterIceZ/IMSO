import sys
input = sys.stdin.readline

def dft(poly: list, inv: bool) -> list:
  if len(poly) == 1:
    return poly
  
  
a = map(int, input().split())
b = map(int, input().split())
x = map(int, input().split())

