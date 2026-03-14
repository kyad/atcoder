import random

L = random.randint(-5, 5)  # a<=N<=b のNを返す
R = random.randint(-5, 5)  # a<=N<=b のNを返す
D = random.randint(-5, 5)  # a<=N<=b のNを返す
U = random.randint(-5, 5)  # a<=N<=b のNを返す
if L > R:
    L, R = R, L
if D > U:
    D, U = U, D
print(L, R, D, U)
