import os
import random

n = 40

test = 0

for i in range(20, n + 1):
  for j in range(1, 2500):
    f = open('test_i.in', 'w')

    f.write(f"{i} {j}\n")

    s = ""
    for _ in range(i):
      t = random.randint(1, 5)
      if t == 1:
        s += '?'
      elif t == 2:
        s += 'A'
      elif t == 3:
        s += 'N'
      elif t == 4:
        s += 'C'
      else:
        s += chr(ord('A')+random.randint(0,25))
    f.write(s)
    f.close()

    os.system("./i2 < test_i.in > out.out")

    f = open("out.out", "r")


    ans = f.readline()
    test += 1
    if ans == "-1":
      pass
    else:
      if len(ans) != i:
        print("ERROR")
        exit(0)
      cnt = 0
      for x in range(0, i):
        for y in range(x+1, i):
          for z in range(y+1, i):
            if ans[x] == 'N' and ans[y] == 'A' and ans[z] == 'C':
              cnt += 1
      if cnt != j:
        print(f"WA, expected {j} found {cnt}")
        exit(0)
    if(test % 100 == 0):
      print(f"Test {test} passed!!")

print("PASSED!")