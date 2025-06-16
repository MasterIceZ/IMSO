#!/bin/python3

n = int(input())
a = list(map(int, input().split()))

cost = []
for i in range(1, 201):
    cost = cost + [i] + ([i * 2] * 9)

a.sort(reverse=True)
cost.sort()

answer = 0
for i in range(n):
    answer += cost[i] * a[i] 

print(answer)
