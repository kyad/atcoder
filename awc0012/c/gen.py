import random

N = random.randint(1, 2*10**5)  # a<=N<=b のNを返す
K = random.randint(1, N)  # a<=N<=b のNを返す
M = random.randint(0, K)  # a<=N<=b のNを返す

H = [0] * N
P = [0] * N
for i in range(N):
    H[i] = random.randint(0, 1)
    P[i] = random.randint(0, 10**9)

print(N, K, M)
for i in range(N):
    print(H[i], P[i])
