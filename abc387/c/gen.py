import random

L = R = 0
while L == R:
    L = random.randint(10, 20)  # a<=N<=b のNを返す
    R = random.randint(10, 20)  # a<=N<=b のNを返す
    if R < L:
        L, R = R, L

print(L, R)
