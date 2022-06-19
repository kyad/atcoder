# https://atcoder.jp/contests/typical90/tasks/typical90_b

import sys

memo = [ {} for i in range(21)]

def f(n):
    if n == 0:
        return {''}
    if n % 2 == 1:
        return {}
    if memo[n]:
        return memo[n]
    ans = { '(' + x + ')' for x in f(n - 2) }
    for k in range(n - 2, 1, -2):
        for x in f(k):
            for y in f(n - k):
                ans.add(x + y)
    memo[n] = ans
    return ans

N = int(input())

print('\n'.join(sorted(f(N))))
