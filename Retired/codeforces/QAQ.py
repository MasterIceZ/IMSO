import sys
input = sys.stdin.readline

s = input()

answer = 0
for i in range(len(s)):
    for j in range(i):
        for k in range(j):
            if s[i] == 'Q' and s[j] == 'A' and s[k] == 'Q':
                answer += 1
print(answer)
