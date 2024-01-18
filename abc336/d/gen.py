import random

#N = random.randint(a, b)  # a<=N<=b のNを返す
N = 9
A = [0] * N
for n in range(N):
    A[n] = random.randint(1, 10)  # a<=N<=b のNを返す

print(N)
print(*A)
