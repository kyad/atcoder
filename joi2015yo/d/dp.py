# https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d

N, M = map(int, input().split())
D = [0] * N
for n in range(N):
    D[n] = int(input())
C = [0] * M
for m in range(M):
    C[m] = int(input())

INF = 1000 * 1000 * 1000 + 1
dp = [[INF] * (M + 1) for n in range(N + 1)]
for m in range(M + 1):
    dp[0][m] = 0
for n in range(1, N + 1):
    for m in range(n, M + 1):
        dp[n][m] = min(dp[n][m - 1], dp[n - 1][m - 1] + C[m - 1] * D[n - 1])

ans = INF
for m in range(N, M + 1):
    ans = min(ans, dp[N][m])
print(ans)
