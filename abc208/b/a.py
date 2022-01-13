# https://atcoder.jp/contests/abc208/tasks/abc208_b

P = int(input())
coin = [1] * 10
for i in range(1, 10):
    coin[i] = coin[i - 1] * (i + 1)
ans = 0
for i in range(9, -1, -1):
    while P >= coin[i]:
        P -= coin[i]
        ans += 1
print(ans)
