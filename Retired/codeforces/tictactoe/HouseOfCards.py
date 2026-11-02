n = int(input())

def check(x):
    return 3 * x * (x + 1) // 2 - x <= n

l = 0
r = 1000000000
while l < r:
    mid = (l + r + 1) // 2
    if check(mid):
        l = mid
    else:
        r = mid - 1

l -= (l + n) % 3
print((l + 2) // 3)
