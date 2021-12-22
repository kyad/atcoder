# https://atcoder.jp/contests/dp/tasks/dp_c
# Python3: AC 578 ms

N = int(input())
value = []
for n in range(N):
    value.append(list(map(int, input().split())))

dp = [[0] * 3 for n in range(N)]

dp[0] = value[0]

for n in range(1, N):
    for i in range(3):
        dp[n][i] = max([dp[n - 1][j] + value[n][i] for j in range(3) if i != j])

print(max(dp[-1]))
