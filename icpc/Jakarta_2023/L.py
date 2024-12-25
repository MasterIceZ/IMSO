n, k = map(int, input().split())

if k < n / 2 or n == k:
  print('-1')
else:
  A = (k - n // 2) // 2
  B = (k - n // 2) - A
  M = n // 2 - A - B
  print("()" * A + "(" * M + ")" * M + "()" * B)