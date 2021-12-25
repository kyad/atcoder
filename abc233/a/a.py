X, Y = map(int, input().split())
Z = Y - X
if (Z > 0):
    ans = (Z + 9) // 10
else:
    ans = 0
print(ans)
