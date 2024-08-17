import random

N = random.randint(1, 3)  # a<=N<=b のNを返す
K = random.randint(0, 8)  # a<=N<=b のNを返す

X = [0] * N
for n in range(N):
    X[n] = random.randint(1, N)  # a<=N<=b のNを返す

A = [0] * N
for n in range(N):
    A[n] = random.randint(1, 10)  # a<=N<=b のNを返す

print(N, K)
print(*X)
print(*A)
