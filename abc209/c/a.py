# https://atcoder.jp/contests/abc209/tasks/abc209_c

N = int(input())
C = list(map(int, input().split()))
C.sort()

MOD = 10 ** 9 + 7
ans = 1
for n, c in enumerate(C):
    ans *= max(0, c - n)
    ans %= MOD
print(ans)
