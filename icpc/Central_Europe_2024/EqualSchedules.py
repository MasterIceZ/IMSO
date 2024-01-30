def parse_input(s: str):
  l = s.split()
  return [(int(l[1]) - int(l[0])), str(l[2])]

d = dict()
names = list()

while True:
  s = input()
  if s == "------":
    break
  val, name = parse_input(s)
  if name not in d:
    d[name] = -val
    names.append(name)
  else:
    d[name] -= val

while True:
  s = input()
  if s == "======":
    break
  val, name = parse_input(s)
  if name not in d:
    d[name] = val
    names.append(name)
  else:
    d[name] += val

printed = False

for name in sorted(names):
  if d[name] == 0:
    continue
  print(name, "+{}".format(d[name]) if d[name] > 0 else d[name])
  printed = True

if not printed:
  print("No differences found.")