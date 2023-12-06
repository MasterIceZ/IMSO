n = int(input())

s = [int(x) for x in input().split()]

print(min(sum(s) // 3, sum(s) - max(s)))
