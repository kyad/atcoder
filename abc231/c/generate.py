import random
N = 2 * 10**5
Q = 2 * 10**5
A = [0] * N
print(N, Q)
for n in range(N):
    A[n] = str(random.randint(1, 10**9))
print(' '.join(A))
for q in range(Q):
    print(random.randint(1, 10**9))
