import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

stack = list()
cnt = 0
for i in range(n):
  while len(stack) > 0 and stack[-1] > a[i]:
    stack.pop()
  if len(stack) > 0 and stack[-1] == a[i]:
    continue
  stack.append(a[i])
  cnt += 1

print(cnt)