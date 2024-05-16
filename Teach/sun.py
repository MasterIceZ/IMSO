l = [["ab", "ab", "xx"], ["ab", "ab", "a"], ["ab", "ac", "a"], ["ab", "ad", "x"], ["b", "x", "a"], ["b", "c", "x"]]

d = dict()
for x in l:
    if x[0] not in d.keys():
        d[x[0]] = []
    d[x[0]].append(x[1])

sorted_keys = sorted(d.keys())

d2 = dict()
sorted_keys_2 = list()

for k in sorted_keys:
    d[k].sort(reverse=True)
    for x in d[k]:
        sorted_keys_2.append([k, x])
        d2[(k, x)] = list()

answer = list()

for x in l:
    d2[(x[0], x[1])].append(x[2])
for k in d2.keys():
    d2[k].sort()
    for x in d2[k]:
        answer.append([k[0], k[1], x])

print(answer)
