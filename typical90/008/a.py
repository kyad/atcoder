# https://atcoder.jp/contests/typical90/tasks/typical90_h

N = int(input())
S = input()

MOD = 10**9 + 7

# dp[i][j]: i文字目まで見て、atcoderのj文字目まで完成している場合の数
# i: 0, 1, ..., N, 1-indexed
# j: 0, 1, ..., 7, 1-indexed
dp = [[0] * (7 + 1) for n in range(N + 1)]
dp[0][0] = 1

T = 'atcoder'

for i in range(0, N):
    for j in range(0, 8):
        # i文字目を取る
        if j <= 6 and S[i] == T[j]:
            dp[i + 1][j + 1] += dp[i][j]
            dp[i + 1][j + 1] %= MOD
        # i文字目を取らない
        dp[i + 1][j] += dp[i][j]
        dp[i + 1][j] %= MOD

print(dp[N][7])
