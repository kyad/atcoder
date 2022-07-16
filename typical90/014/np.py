# https://atcoder.jp/contests/typical90/tasks/typical90_n

import numpy as np

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A = np.array(A)
B = np.array(B)
A.sort()
B.sort()
ans = np.sum(np.abs(A - B))
print(ans)
