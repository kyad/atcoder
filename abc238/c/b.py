MOD = 998244353;

def digit(n):
    ans = 1
    while n >= 10:
        n = n // 10
        ans += 1
    return ans

N = int(input())

K = digit(N)
ans = 0
for k in range(1, K + 1):
    base = 10**(k - 1) - 1
    mx = 10**k - 1
    n = min(N - base, mx - base)
    temp = n * (n + 1) // 2
    ans += temp
ans %= MOD
print(ans)
