import random

#N = random.randint(3, 8)  # a<=N<=b のNを返す
#M = random.randint(3, 8)  # a<=N<=b のNを返す
N = random.randint(7, 7)  # a<=N<=b のNを返す
M = random.randint(7, 7)  # a<=N<=b のNを返す
#N = random.randint(300, 300)  # a<=N<=b のNを返す
#M = random.randint(300, 300)  # a<=N<=b のNを返す
print(N, M)
for n in range(N):
    T = random.randint(1, M)  # a<=N<=b のNを返す
    print(T)
    l = list(range(1, M + 1))
    A = sorted(random.sample(l, k=T))
    print(*A)
S = [0] * M
for m in range(M):
    S[m] = random.randint(0, 1)
print(*S)
