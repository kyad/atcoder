# https://atcoder.jp/contests/dp/tasks/dp_b

import sys
import numpy as np

N, K = map(int, input().split())
H = np.array(list(map(int, sys.stdin.readline().split())), dtype=np.int32)
INF = 10 ** 5 * 10 ** 4 + 1
dp = np.full(N, INF, dtype=np.int32)
dp[0] = 0
for i in range(1, N):
    for j in range(1, K + 1):
        k = i - j
        if k < 0:
            continue
        dp[i] = min(dp[i], dp[k] + abs(H[k] - H[i]))
print(dp[N - 1])
