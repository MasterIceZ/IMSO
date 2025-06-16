#!/bin/python3

n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)

cur = 1
answer = 0
avail = [1] * (200 + 200 + 1)

for ele in a:
    answer += ele * cur
    avail[cur] -= 1
    if avail[cur] == 0:
        avail[cur * 2] += 9
        cur += 1

print(answer)
