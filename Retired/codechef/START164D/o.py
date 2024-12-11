r = 1e9
s = 1
i = 0

while s <= r:
	s *= (1 << i)
	i += 1
print(s, i)
