# https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c

N, M = map(int, input().split())
A = []
for n in range(N):
    A.append(list(map(int, input().split())))
ans = 0
for t1 in range(M):
    for t2 in range(t1 + 1, M):
        score = 0
        for n in range(N):
            score += max(A[n][t1], A[n][t2])
        ans = max(ans, score)
print(ans)
