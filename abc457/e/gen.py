import random

N = 5 #random.randint(1, 5)  # a<=N<=b のNを返す
M = 3 #random.randint(1, 5)  # a<=N<=b のNを返す
print(N, M)
for j in range(M):
    L = random.randint(1, N)  # a<=N<=b のNを返す
    R = random.randint(1, N)  # a<=N<=b のNを返す
    if L > R:
        L, R = R, L
    print(L, R)

Q = 1
print(Q)
for q in range(Q):
    S = random.randint(1, N)  # a<=N<=b のNを返す
    T = random.randint(1, N)  # a<=N<=b のNを返す
    if S > T:
        S, T = T, S
    print(S, T)
