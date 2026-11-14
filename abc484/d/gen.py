import random

# N = random.randint(a, b)  # a<=N<=b のNを返す
N = 4

A = [0] * N
for n in range(N):
    A[n] = random.randint(1, N)  # a<=N<=b のNを返す

print(N)
print(*A)
