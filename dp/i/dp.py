# https://atcoder.jp/contests/dp/tasks/dp_i
# Python3: TLE
# PyPy3: AC

N = int(input())
P = [0] + list(map(float, input().split()))
dp = [ [0] * (N + 1) for n in range(N + 1) ]
dp[0][0] = 1
for n in range(N):
    for m in range(N + 1):
        dp[n + 1][m] += (1 - P[n + 1]) * dp[n][m]
        if m + 1 <= N:
            dp[n + 1][m + 1] += P[n + 1] * dp[n][m]
ans = 0
for m in range((N + 1) // 2, N + 1):
    ans += dp[N][m]
print(ans)
