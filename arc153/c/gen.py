import random

N = random.randint(1, 10000)  # a<=N<=b のNを返す
#N = random.randint(1, 10)  # a<=N<=b のNを返す
A = [0] * N
for n in range(N):
    A[n] = random.randint(1, 2)  # a<=N<=b のNを返す
    if A[n] == 2:
        A[n] = -1

print(N)
print(*A)
