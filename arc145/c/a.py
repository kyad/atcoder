# https://atcoder.jp/contests/arc145/tasks/arc145_c

N = int(input())
MOD = 998244353
ans = 2 ** N
ans %= MOD
for i in range(N + 2, 2 * N + 1):
    ans *= i
    ans %= MOD
print(ans)
