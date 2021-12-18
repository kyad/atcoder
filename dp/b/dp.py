# https://atcoder.jp/contests/dp/tasks/dp_b
# Python3: TLE
# PyPy3: AC

N, K = map(int, input().split())
H = list(map(int, input().split()))
INF = 10 ** 5 * 10 ** 4 + 1
dp = [INF] * N
dp[0] = 0
for i in range(1, N):
    for j in range(1, K + 1):
        k = i - j
        if k < 0:
            continue
        dp[i] = min(dp[i], dp[k] + abs(H[k] - H[i]))
print(dp[N - 1])
