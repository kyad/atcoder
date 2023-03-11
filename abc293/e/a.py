A, X, M = map(int, input().split())

if A == 1:
    ans = X % M
elif M == 1:
    ans = 0
else:
    denom = A - 1
    mod = M * denom
    numer = (pow(A, X, mod) + mod - 1) % mod
    ans = numer // denom
print(ans)
