f = open("input.txt", "r")

cnt = 0

for line in f:
    sp_line = line.split(",")
    a = sp_line[0]
    b = sp_line[1]
    a = [int(i) for i in a.split("-")]
    b = [int(i) for i in b.split("-")]

    if a[0] <= b[0] and b[1] <= a[1]:
        cnt += 1
    elif b[0] <= a[0] and a[1] <= b[1]:
        cnt += 1
    elif a[0] <= b[0] and b[0] <= a[1]:
        cnt += 1
    elif b[0] <= a[0] and a[0] <= b[1]:
        cnt += 1

print(cnt)
