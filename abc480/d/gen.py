import random

#N = random.randint(1, 10)  # a<=N<=b のNを返す
N = 10**5
Q = 1
A = [0] * N
for i in range(N):
    #A[i] = random.randint(-10, 10)  # a<=N<=b のNを返す
    A[i] = random.randint(-10**8, 10**8)  # a<=N<=b のNを返す

print(N, Q)
print(*A)
for q in range(Q):
    L = random.randint(1, N*(N+1)//2)  # a<=N<=b のNを返す
    R = random.randint(1, N*(N+1)//2)  # a<=N<=b のNを返す
    if L > R:
        L, R = R, L
    print(L, R)
