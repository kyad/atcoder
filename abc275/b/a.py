A, B, C, D, E, F = map(int, input().split())
MOD = 998244353
p = A * B
p %= MOD
p *= C
p %= MOD

q = D * E
q %= MOD
q *= F
q %= MOD

ans = (p + MOD) - q
ans %= MOD

print(ans)
