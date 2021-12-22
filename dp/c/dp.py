# https://atcoder.jp/contests/dp/tasks/dp_c
# Python3: AC 688 ms
# PyPy3: AC 261 ms

N = int(input())
value = []
for n in range(N):
    value.append(list(map(int, input().split())))

dp = [[0] * 3 for n in range(N)]

for i in range(3):
    dp[0][i] = value[0][i]

for n in range(1, N):
    for i in range(3):
        for j in range(3):
            if i == j:
                continue
            dp[n][i] = max(dp[n][i], dp[n - 1][j] + value[n][i])

print(max(dp[-1]))
