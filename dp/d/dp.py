# https://atcoder.jp/contests/dp/tasks/dp_d
# PyPy3: AC

N, W = map(int, input().split())
w = [0] * (N + 1)
v = [0] * (N + 1)
for n in range(1, N + 1):
    w[n], v[n] = map(int, input().split())
dp = [[-1] * (W + 1) for n in range(N + 1)]
dp[0][0] = 0

for n in range(0, N):
    for j in range(0, W):
        if dp[n][j] < 0:
            continue
        dp[n + 1][j] = max(dp[n + 1][j], dp[n][j])
        if j + w[n + 1] <= W:
            dp[n + 1][j + w[n + 1]] = max(dp[n + 1][j + w[n + 1]], dp[n][j] + v[n + 1])
print(max(dp[N]))
