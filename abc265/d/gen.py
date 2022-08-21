import random
N = 10
P = 2
Q = 3
R = 4
A = [0] * N
for n in range(N):
    A[n] = random.randint(1, 5)
print(N, P, Q, R)
print(*A, sep=" ")
