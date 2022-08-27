N = int(input())
MOD = 998244353
if N >= 0:
    print(N % MOD)
else:
    ans = (-N) % MOD
    ans = -ans
    ans += MOD
    ans %= MOD
    print(ans)
