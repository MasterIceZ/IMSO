import sys
input = sys.stdin.readline

MOD = 998244353

def mop(a, b):
    global MOD
    res = 1
    while b > 0:
        if b % 2 == 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b //= 2
    return res

for _ in range(int(input())):
    n = int(input())
    answer = 0
    for i in range(2, n + 2):
        answer = (answer + mop(i, MOD - 2)) % MOD
    answer = (answer * (n + 1)) % MOD
    print(answer)
