import random

N = 5
K = 20
A = [0] * N
for n in range(N):
    A[n]= random.randint(1, 10)
print(N, K)
print(*A)
