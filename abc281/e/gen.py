import random

K = random.randint(1, 2)  # a<=N<=b のNを返す
M = random.randint(K, 2)  # a<=N<=b のNを返す
N = random.randint(M, 2)  # a<=N<=b のNを返す

A = [0] * N
for n in range(N):
    A[n] = random.randint(1, 10)  # a<=N<=b のNを返す

print(N, M, K)
print(*A)
