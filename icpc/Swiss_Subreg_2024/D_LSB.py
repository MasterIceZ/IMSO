import math

n = int(input()) # number of bits

t = math.ceil(math.log2(n))
print(t * 2 + 2)
max_pos = 1
i = 0
while max_pos < n:
  print(f"B{i + 1} = B{i} << {max_pos}")
  print(f"B{i + 2} = B{i + 1} | B{i}")
  max_pos *= 2
  i += 2
print(f"B{i + 1} = B{i} << 1")
print(f"B{i + 2} = B{i + 1} ^ B{i}")