now = ""

def isOpr(x):
    return x == '*' or x == '+' or x == '^'

def pri(x):
    if x == '+':
        return 1
    if x == '*':
        return 2
    if x == '^':
        return 3

def calc(idx):
    global now
    if now == "null":
        return 
    n = len(now)
    ok = False
    b = 0
    for i in range(1, n - 1):
        if now[i] == '(':
            b += 1
        if now[i] == ')':
            b -= 1
        if b < 0:
            ok = True
    if not ok and now[0] == '(' and now[n - 1] == ')' and b == 0:
        if idx == 1:
            now = s[1:n-1]
            return 
        else :
            now = "null"
            return 
    b = 0
    min_opr = 3
    for x in now:
        if x == '(':
            b += 1
        elif x == ')':
            b -= 1
        if isOpr(x) and b == 0:
            min_opr = min(min_opr, pri(x))
    have = []
    o = ""
    b = 0
    for i in range(n):
        if now[i] == '(':
            b += 1
        if now[i] == ')':
            b -= 1
        if isOpr(now[i]) and pri(now[i]) == min_opr and b == 0:
            have.append(o)
            o = ""
        else :
            o += now[i]
    have.append(o)
    if len(have) < idx :
        now = "null"
        return 
    else :
        now = have[idx - 1]
        return

s = input()
q = int(input())

for i in range(q):
    now = s
    st = []
    _ = input().split()
    sz = 0
    for j in range(len(_)):
        x = int(_[j])
        if x == 0:
            break
        st.append(str(x))
        sz += 1
        if now == "null":
            continue
        calc(x)
    while len(st):
        print("op(" + st.pop() + ",",end="")
    print("p",end="")
    for j in range(sz):
        print(")",end="")
    print("=" + now)
