import sys
input=sys.stdin.readline

n, s = map(int, input().split())

a = sorted(list(map(int, input().split())))

l = 0
r = min(n, s)
if r <= 2:
    print(r)
a = a[:-2] # use 2 maxes
n -= 2
s -= 2
r = min(n, s)

while l < r:
    mid = (l + r + 1) // 2
    cnt_mod = [0, 0, 0]
    for x in a[:mid]:
        cnt_mod[x % 3] += 1
    combine = min(cnt_mod[1], cnt_mod[2])
    cnt_mod[1] -= combine
    cnt_mod[2] -= combine
    tot = sum(a[:mid])
    if cnt_mod[1] > 0:
        tot += cnt_mod[1] // 2 + 2 * (cnt_mod[1] % 2)
    if cnt_mod[2] > 0:
        tot += cnt_mod[2]
    if tot <= 3 * s:
        l = mid
    else:
        r = mid - 1

print(l + 2)
