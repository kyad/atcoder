# https://atcoder.jp/contests/dp/tasks/dp_e
# PyPy3: AC

N, W = map(int, input().split())
w = [0] * N
v = [0] * N
for n in range(N):
    w[n], v[n] = map(int, input().split())
INF = W + 1
V_MAX = 10 ** 3 * N
dp = [INF] * (V_MAX + 1)
dp[0] = 0

for n in range(N):
    for j in range(V_MAX, -1, -1):
        if j - v[n] < 0:
            continue
        dp[j] = min(dp[j], dp[j - v[n]] + w[n])
for j in range(V_MAX, -1, -1):
    if dp[j] < INF:
        print(j)
        break
