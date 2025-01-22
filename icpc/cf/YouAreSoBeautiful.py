import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [*map(int, input().split())]

    mem = dict()
    mem2 = dict()
    for i, x in enumerate(a):
        if x not in mem:
            mem[x] = i
        mem2[x] = i
    answer = 0
    cnt = 0
    for i, x in enumerate(a):
        if mem[x] == i:
            cnt += 1
        if mem2[x] == i:
            answer += cnt
    print(answer)

for _ in range(int(input())):
    solve()
