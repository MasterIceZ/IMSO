import sys
input = sys.stdin.readline

MOD = 10**9 + 7

def solve():
  n, k = map(int, input().split())
  fibo = [0, 1]
  cnt_iter = 1
  while fibo[1] % k != 0:
    fibo = [fibo[1], (fibo[0] + fibo[1]) % k]
    cnt_iter += 1
  n %= MOD
  cnt_iter %= MOD
  print((cnt_iter * n) % MOD)

for _ in range(int(input())):
  solve()