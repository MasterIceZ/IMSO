def ask(x, y, z):
    print(x, y, z)
    return int(input())

x=ask(1, 0, 0)
y=ask(0, 1, 0)
z=ask(0, 0, 1)
a=ask(1, 1, 1)
b=ask(1, 2, 3)

if x + y + z == a:
    print(x, y, z)
elif x + 2 * y + 3 * z == b:
    print(x, y, z)
elif (a - y - z) + 2 * y + 3 * z == b:
    print(a - y - z, y, z)
elif x + 2 * (a - x - z) + 3 * z == b:
    print(x, a - x - z, z)
else:
    print(x, y, a - x - y)
