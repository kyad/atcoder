# https://atcoder.jp/contests/abc262/tasks/abc262_d

N = int(input())
A = list(map(int, input().split()))
A.insert(0, 0)  # 1-indexed

MOD = 998244353

ans = 0
# S: 選ぶ個数
for S in range(1, N + 1):
    # dp[i][j][k]: i(1<=i<=N)までのうちj個(0<=j<=S)選んだ時にSで割った余りがk(0<=k<S)の個数
    dp = [ [ [0] * S for j in range(S + 1) ] for i in range(N + 1) ]
    dp[0][0][0] = 1
    for i in range(1, N + 1):
        for j in range(S + 1):
            for k in range(S):
                if j > 0:
                    # A[i]を取る
                    nk = (k - A[i] % S + S) % S
                    dp[i][j][k] += dp[i - 1][j - 1][nk]
                    dp[i][j][k] %= MOD
                # A[i]を取らない
                dp[i][j][k] += dp[i - 1][j][k]
                dp[i][j][k] %= MOD
    ans += dp[N][S][0]
    ans %= MOD

print(ans)
