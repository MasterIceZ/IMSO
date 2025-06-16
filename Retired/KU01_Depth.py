import sys
input = sys.stdin.readline

n, q = map(int, input().split())
stk = list()
t = 0
mx = [0] * (n + 1)
for i in range(n):
    d, l = map(int, input().split())
    if d == 1:
        stk.append(l)
    else:
        l += stk[-1]
        stk.pop(-1)

        if t > 0:
            l += stk[-1]
            stk.pop(-1)

        stk.append(l)
    if mx[-1] < stk[-1]:
        mx[-1] = stk[-1]

for _ in range(q):
    x = int(input())
    l = 1
    r = n
    while l < r:
        mid = (l + r + 1) // 2
        if mx[mid] >= x:
            l = mid
        else:
            r = mid - 1
print(l)
