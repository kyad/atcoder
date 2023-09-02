import random

#N = random.randint(5, 7)  # a<=N<=b のNを返す
#N = random.randint(10, 20)  # a<=N<=b のNを返す
#N = 100
#N = 1000
N = 10000
#N = 2*10**5

A = [0] * N
for n in range(N):
    A[n] = random.randint(1, N)  # a<=N<=b のNを返す

print(N)
print(*A)
