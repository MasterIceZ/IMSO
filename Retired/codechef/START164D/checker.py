from itertools import permutations
import sys

l = [int(x) for x in input().split()]
n = len(l)
ok = True

print(f"Checking: {l}...")

for i in range(0, n + 1):
	for j in range(i + 1, n + 1):
		s = sum([x for x in l[i:j + 1]])
		if s % (n + 1) == 0:
			ok = False
			print(f"Error Found!: ({i}, {j}) = {s}")
			sys.exit(0)
		
print("ok!")	
