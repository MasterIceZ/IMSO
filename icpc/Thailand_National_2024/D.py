import sys
input = sys.stdin.readline

def solve_equation(a_1, b_1, a_2, b_2):
  # S * a + R = b
  a_diff = a_1 - a_2
  b_diff = b_1 - b_2
  if a_diff == 0:
    if b_diff != 0:
      print(-1)
      sys.exit(0)
    return False, -1
  if b_diff % a_diff != 0:
    print(-1)
    sys.exit(0)
  s = b_diff // a_diff
  # R = b - S * a
  r = b_1 - s * a_1
  return s, r

n = int(input())
dis_infe = sorted([map(int, input().split()) for i in range(n)])
bacteria = sorted([map(int, input().split()) for i in range(n)])

s_set = set()

for i in range(0, n):
  for j in range(0, i):
    cur_s, cur_r = solve_equation(dis_infe[j][0], dis_infe[j][1])