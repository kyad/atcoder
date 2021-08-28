import math
N = int(input())
ans = 0
for k in range(60):
    if (2 ** k <= N):
        ans = k
    else:
        break
print(ans)
