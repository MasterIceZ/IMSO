def f_lg(x):
    return x.bit_length() - 1

for _ in range(int(input())):
    n = int(input())
    a = map(int, input().split())
    cnt = dict()
    for x in a:
        if x == 0:
            continue
        t = f_lg(x)
        if t not in cnt:
            cnt[t] = 0
        cnt[t] += 1
    if len(cnt) > 0:
        print(max(cnt.values()))
    else:
        print(1)
