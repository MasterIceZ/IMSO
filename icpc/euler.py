import math

n = int(input())

a = int(input())
b = int(input())
c = int(input())
d = int(input())

if a < c:
    a, c = c, a
    b, d = d, b

k = math.gcd(a - c, b - d)
h = math.gcd(a + c, b + d)
l = math.gcd(a + c, b - d)
m = math.gcd(a - c, b + d)

print((k // 2) ** 2 + (h // 2) ** 2)
print(l ** 2 + m ** 2)
