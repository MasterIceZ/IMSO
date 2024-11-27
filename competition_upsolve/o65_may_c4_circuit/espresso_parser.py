a = input()

tokens = a.split(" | ")
l = list()
for token in tokens:
  token = token[1:-1]
  cur_l = list()
  for x in token.split("&"):
    if x[0] == "!":
      cur_l.append(-(ord(x[1]) - ord('A') + 1))
    else:
      cur_l.append(ord(x[0]) - ord('A') + 1)
  l.append(cur_l)
print(len(l))
for x in l:
  print(len(x), end=" ")
  print(" ".join(map(str, x)))