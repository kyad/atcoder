n, Y = map(int, input().split())
for x in range(n + 1):
    for y in range(n - x + 1):
        z = n - x - y
        if 10000 * x + 5000 * y  + 1000 * z == Y:
            print("{} {} {}".format(x, y, z))
            exit(0)
print("-1 -1 -1")
