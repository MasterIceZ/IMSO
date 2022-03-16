def p(x):
    print(x, end="")

s = input()

for i in range(0, 5):
    for j in range(0, len(s)):
        if i != 2 :
            p('.')
        elif j == 0 or j % 3 == 1:
            p('#')
        else:
            p('*')
        for k in range(0, 3):
            if (i + k) % 2:
                if i == 2 and k == 1:
                    p(s[j])
                elif j % 3 == 2:
                    p('*')
                else :
                    p('#')
            else:
                p('.')
    if i != 2:
        p('.')
    elif len(s) % 3:
        p('#')
    else :
        p('*')
    p('\n')
