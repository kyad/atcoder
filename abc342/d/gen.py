import random

#N = random.randint(a, b)  # a<=N<=b のNを返す
N = 5

A = [0] * N
for n in range(N):
    A[n] = random.randint(0, 20)  # a<=N<=b のNを返す

print(N)
print(*A)
