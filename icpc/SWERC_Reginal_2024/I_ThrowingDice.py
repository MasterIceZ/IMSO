n, m = map(int, input().split())

a = sum(map(int, input().split())) + n
b = sum(map(int, input().split())) + m

print("TIED" if a == b else "ALICE" if a > b else "BOB")
