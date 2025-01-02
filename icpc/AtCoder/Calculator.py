s = input()

cnt = 0
last = "?"
for i in range(len(s)):
  if s[i] != '0':
    cnt += 1
    last = "?"
  else:
    if last != '0':
      cnt += 1
      last = s[i]
    else:
      last = "?"
print(cnt)