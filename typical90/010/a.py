# https://atcoder.jp/contests/typical90/tasks/typical90_j

N = int(input())
a1 = [0] * (N + 1)
a2 = [0] * (N + 1)
for i in range(1, N + 1):
    c, p = map(int, input().split())
    if c == 1:
        a1[i] = a1[i - 1] + p
        a2[i] = a2[i - 1]
    else:
        a1[i] = a1[i - 1]
        a2[i] = a2[i - 1] + p
Q = int(input())
for i in range(Q):
    l, r = map(int, input().split())
    print('{} {}'.format(a1[r] - a1[l - 1], a2[r] - a2[l - 1]))
