import random

N = 3
H = 3
W = 2
print(N, H, W)
for n in range(N):
    A = random.randint(1, H)
    B = random.randint(1, W)
    print(A, B)
