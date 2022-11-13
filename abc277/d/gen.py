import random

N = random.randint(3, 5)  # a<=N<=b のNを返す
M = random.randint(2, 4)  # a<=N<=b のNを返す

print(N, M)

A = [0] * N

for n in range(N):
    A[n] = random.randint(0, M - 1)
print(*A)
