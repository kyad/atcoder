A, B, C = sorted(list(map(int, input().split())))
k = A + B - C
if k < 0:
    print(-1)
else:
    print(C)
