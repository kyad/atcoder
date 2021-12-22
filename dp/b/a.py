# https://atcoder.jp/contests/dp/tasks/dp_b
# Python3: AC

N, K = map(int, input().split())
H = list(map(int, input().split()))
dp = [0] * N
for i in range(1, N):
    dp[i] = min([dp[k] + abs(H[k] - H[i]) for k in range(max(0, i - K), i)])
print(dp[N - 1])
