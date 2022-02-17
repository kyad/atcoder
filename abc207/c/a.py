# https://atcoder.jp/contests/abc207/tasks/abc207_c

N = int(input())
X = []
for n in range(N):
    t, l, r = map(int, input().split())
    if t == 1:
        X.append((l, r))
    elif t == 2:
        X.append((l, r - 0.1))
    elif t == 3:
        X.append((l + 0.1, r))
    else:
        X.append((l + 0.1, r - 0.1))
ans = 0
for i in range(N):
    for j in range(i + 1, N):
        al = X[i][0]
        ar = X[i][1]
        bl = X[j][0]
        br = X[j][1]
        if ar < bl or br < al:
            continue
        ans += 1
print(ans)
