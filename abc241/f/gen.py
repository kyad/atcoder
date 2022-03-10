import random

H = random.randint(1, 10**9)
W = random.randint(1, 10**9)
N = random.randint(1, 10**5)
SY = 1
SX = 1
GY = H
GX = W

print(H, W, N)
print(SY, SX)
print(GY, GX)

for n in range(N):
    Y = random.randint(2, H - 1)
    X = random.randint(2, W - 1)
    print(Y, X)
