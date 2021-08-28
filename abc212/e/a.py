# https://atcoder.jp/contests/abc212/tasks/abc212_e

MOD = 998244353
N, M, K = map(int, input().split())
graph = [[] for n in range(N)]
for m in range(M):
    U, V = map(int, input().split())
    graph[U - 1].append(V - 1)
    graph[V - 1].append(U - 1)
dp = [[0] * N for k in range(K + 1)]
dp[0][0] = 1
for k in range(1, K + 1):
    total = 0
    for n in range(N):
        total += dp[k - 1][n]
    total %= MOD
    for n in range(N):
        dp[k][n] = total - dp[k - 1][n]
        dp[k][n] %= MOD
        for v in graph[n]:
            dp[k][n] -= dp[k - 1][v]
            dp[k][n] %= MOD
print(dp[K][0] % MOD)
