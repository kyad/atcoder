import math
A, B = map(int, input().split())
g = math.gcd(A, B)
l = A // g * B
if l > 10**18:
    print("Large")
else:
    print(l)
