t = int(input())

while t > 0:
  t -= 1
  a, b, c = map(int, input().split())
  if c == 0:
    print("NO CURVE")
  else:
    print("CURVE DOWN" if c < 0 else "CURVE UP")