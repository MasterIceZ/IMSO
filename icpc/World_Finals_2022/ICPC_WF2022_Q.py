class fenwick:
    def build(self, n):
        i = 1
        while i <= n:
            self.t[i] += 1;
            nxt = i + (i &-i);
            if nxt < len(self.t):
                self.t[nxt] += self.t[i]
            i = i + 1

    def update(self, idx, v):
        while idx < len(self.t):
            self.t[idx] += v
            idx = idx + (idx & -idx)

    def query(self, idx):
        res = 0
        while idx > 0:
            res += self.t[idx]
            idx = idx - (idx & -idx)
        return res

    def __init__(self, n):
        self.t = [0 for i in range(0, n + 1)]

n = int(input())
fw = fenwick(n)
fw.build(n)
answer = 2 * n
last = n + 1

for x in map(int, input().split()):
    fw.update(x, -1)
    answer += fw.query(n) - fw.query(min(last, x))
    last = x

print(f"{answer / 2:.4f}")
