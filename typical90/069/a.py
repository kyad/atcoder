N, K = map(int, input().split())
MOD = 10**9+7
ans = K
ans %= MOD
if N >= 2:
    ans *= (K - 1)
    ans %= MOD
if N >= 3:
    ans *= pow(K - 2, N - 2, MOD)
    ans %= MOD
print(ans)
