# https://atcoder.jp/contests/abc209/tasks/abc209_b

N, X = map(int, input().split())
A = list(map(int, input().split()))
sum = 0
for i, a in enumerate(A):
    if i % 2 == 1:
        sum += (a - 1)
    else:
        sum += a
print('Yes' if X >= sum else 'No')
