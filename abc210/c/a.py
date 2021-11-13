# https://atcoder.jp/contests/abc210/tasks/abc210_c

N, K = map(int, input().split())
c = list(map(int, input().split()))
dic = {}
ans = 0
for n in range(N):
    # Increment c[n]
    if c[n] in dic:
        dic[c[n]] += 1
    else:
        dic[c[n]] = 1
    if n >= K - 1:
        ans = max(ans, len(dic))
        # Decrement c[n - K + 1]
        if dic[c[n - K + 1]] == 1:
            dic.pop(c[n - K + 1])
        else:
            dic[c[n - K + 1]] -= 1
print(ans)
