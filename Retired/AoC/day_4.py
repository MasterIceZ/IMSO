f = open("input.txt", "r")

cnt = 0

for line in f:
    sp_line = line.split(",")
    a = sp_line[0]
    b = sp_line[1]
    a = [int(i) for i in a.split("-")]
    b = [int(i) for i in b.split("-")]

    aa = range(a[0], a[1])
    bb = range(b[0], b[1])

    if any(x in aa for x in bb):
        cnt += 1

print(cnt)
