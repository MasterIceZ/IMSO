import math

n = int(input())
n = n * n
for a in range(0, n):
  for b in range(0, n):
    if math.gcd(n, b) == 1 and math.gcd(n, a) == 1 and math.gcd(a + b, n) == 1 and math.gcd(a - b, n) == 1:
      print(a, b)
      exit()