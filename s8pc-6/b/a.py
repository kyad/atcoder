# https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b

import numpy as np

N = int(input())
A = np.empty(N, dtype=np.int64)
B = np.empty(N, dtype=np.int64)
for n in range(N):
    A[n], B[n] = map(int, input().split())

INF = 10 ** 9 * N + 1
ans = 0
Smin = INF
for start in range(N):
    sum = 0
    for n in range(N):
        sum += abs(A[n] - A[start])
    Smin = min(Smin, sum)
ans += Smin

for n in range(N):
    ans += abs(A[n] - B[n])

Tmin = INF
for end in range(N):
    sum = 0
    for n in range(N):
        sum += abs(B[n] - B[end])
    Tmin = min(Tmin, sum)
ans += Tmin

print(ans)
