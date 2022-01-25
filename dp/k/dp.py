# https://atcoder.jp/contests/dp/tasks/dp_k
# PyPy3: AC

N, K = map(int, input().split())
A = list(map(int, input().split()))
# dp[k]: 残りk個から始めた時に、自分が勝ち確定なら1、相手が勝ち確定なら0
dp = [-1] * (K + 1)

# 初期条件
for k in range(A[0]):
    dp[k] = 0
for n in A:
    dp[n] = 1

for k in range(K + 1):
    if dp[k] >= 0:
        continue
    # dp[k] = dp[k-n]がどれか0なら1、どれも1なら0
    dp[k] = 0
    for n in A:
        i = k - n
        if i < 0:
            continue
        if dp[i] == 0:
            dp[k] = 1

print('First' if dp[K] == 1 else 'Second')
