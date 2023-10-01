import random

N = 100
K = 5
P = 5

print(N, K, P)
for n in range(N):
    C = 10**9
    A = [0] * K
    for k in range(K):
        A[k] = random.randint(0, P)  # a<=N<=b のNを返す
    print(C, *A)
