n = int(input())

d = dict()

for i in range(n):
    s = input().split()
    s1 = s[0] + s[1]
    s2 = s[2] + s[3]
    if s1 not in d:
        d[s1] = 0
    d[s1] += 1
    if s2 not in d:
        d[s2] = 0
    d[s2] += 1

for k in d.keys():
    if d[k] % 2 == 1:
        print("yes")
        exit()
print("no")
