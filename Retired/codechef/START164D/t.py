from itertools import permutations
import sys
# from tqdm import tqdm

n = int(input())

perms = list(permutations([i for i in range(1, n + 1)]))

for i in range(len(perms)):
#	if i % 5 == 0:
#		print(f"{i} / {len(perms)}")
	p = perms[i]
	ok = True
	for i in range(0, n + 1):
		for j in range(i + 1, n + 1):
			if sum([x for x in p[i:j + 1]]) % (n + 1) == 0:
				ok = False
	if ok:
		print(p)
				
