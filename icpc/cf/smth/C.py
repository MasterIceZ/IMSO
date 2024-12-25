import sys

for _ in range(int(sys.readline().strip())):
  s = sys.readline().strip()
  
  n = len(s)
  count = {0 for i in range(0, 10)}
  for i in s:
    count[int(i)] += 1
  sm = 0
  for i in range(0, 10):
    sm += i * count[i]
  remains = sm % 9
  if remain 
  