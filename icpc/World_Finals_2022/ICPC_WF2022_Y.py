s = input()

answer = ""

for x in s:
    if len(answer) == 0 or answer[-1] != x:
        answer += x
while len(answer) >= 4:
    answer = answer[:-2]

print(answer)
