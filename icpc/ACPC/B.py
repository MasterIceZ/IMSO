for _ in range(int(input())):
    l = input()
    print(9 - (sum([*map(int, input().split())]) % 9))
