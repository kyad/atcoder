# https://atcoder.jp/contests/typical90/tasks/typical90_x

N, K = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

sum = 0
for a, b in zip(A, B):
    sum += abs(a - b)

K -= sum
if K < 0:
    print("No")
else:
    print("Yes" if K % 2 == 0 else "No")
