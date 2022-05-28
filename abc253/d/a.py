from math import gcd
def S(n):
    return n * (n + 1) // 2

def lcm(a, b):
    return a // gcd(a, b) * b

N, A, B = map(int, input().split())
na = N // A
nb = N // B
l = lcm(A, B)
nl = N // l
ans = S(N) - S(na) * A - S(nb) * B + S(nl) * l
print(ans)
