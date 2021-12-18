# https://atcoder.jp/contests/dp/tasks/dp_a

import numpy as np

N = int(input())
H = np.array(list(map(int, input().split())), dtype=np.int32)
dp = np.zeros(N, dtype=np.int32)
dp[0] = 0
dp[1] = abs(H[1] - H[0])
for k in range(2, N):
    dp[k] = min(dp[k - 1] + abs(H[k - 1] - H[k]),
                dp[k - 2] + abs(H[k - 2] - H[k]))
print(dp[N - 1])
