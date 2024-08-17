import random

N = random.randint(2, 4)  # a<=N<=b のNを返す
M = random.randint(1, 4)
print(N, M)

A = [0] * N
for n in range(N):
    A[n] = random.randint(1, 5)
print(*A)
