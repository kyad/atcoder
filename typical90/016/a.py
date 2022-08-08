# https://atcoder.jp/contests/typical90/tasks/typical90_p

import math

N = int(input())
A, B, C = map(int, input().split())

ans = math.inf
for a in range (0, min(N // A, 9999) + 1):
    for b in range(0, min((N - a * A) // B, 9999) + 1):
        R = N - a * A - b * B
        if R % C == 0:
            c = R // C
            ans = min(ans, a + b + c)
print(ans)
