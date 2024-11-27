n,t=map(int,input().split())
for i in range(1,n+1):
  x = int(input())
  t -= x - 1
  if (t-1)//x+1<i:
    print(i - 1)
    exit(0)
print(n)
