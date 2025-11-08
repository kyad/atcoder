import random

N = random.randint(1, 5)  # a<=N<=b のNを返す
M = random.randint(1, 5)  # a<=N<=b のNを返す
K = random.randint(1, min(N, M))  # a<=N<=b のNを返す

MAX = 10

H = [0] * N
for n in range(N):
    H[n] = random.randint(1, MAX)

B = [0] * M
for m in range(M):
    B[m] = random.randint(1, MAX)

print(N, M, K)
print(*H)
print(*B)
