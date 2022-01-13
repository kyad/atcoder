# https://atcoder.jp/contests/abc208/tasks/abc208_c

N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = [K // N] * N
K %= N

array = []
for n in range(N):
    array.append((A[n], n))
array.sort()
for n in range(K):
    ans[array[n][1]] += 1
for n in range(N):
    print(ans[n])
