n, m = map(int, input().split())

s = 0
for i in range(n):
    s += sum(map(int, input().split()))

print(s / (n * m))
