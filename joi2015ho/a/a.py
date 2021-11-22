# https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_a

import sys

N, M = map(int, input().split())
P = list(map(int, sys.stdin.readline().split()))
for m in range(M):
    P[m] -= 1

A = [0] * (N - 1)
B = [0] * (N - 1)
C = [0] * (N - 1)
for n in range(N - 1):
    A[n], B[n], C[n] = map(int, sys.stdin.readline().split())

imos = [0] * N
for m in range(M - 1):
    a = min(P[m], P[m + 1])
    b = max(P[m], P[m + 1])
    imos[a] += 1
    imos[b] -= 1

for n in range(N - 1):
    imos[n + 1] += imos[n]

ans = 0
for n in range(N - 1):
    ans += min(A[n] * imos[n], B[n] * imos[n] + C[n])

print(ans)
