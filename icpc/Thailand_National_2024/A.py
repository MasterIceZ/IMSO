n = int(input())
res = 0
for i in range(n - 1, 1, -2):
  res += 1 + (i * (i - 1) // 2)
print(res)