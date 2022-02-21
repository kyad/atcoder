# https://atcoder.jp/contests/abc206/tasks/abc206_b

N = int(input())

for d in range(1000000):
    sum = d * (d + 1) // 2
    if sum >= N:
        break
print(d)
