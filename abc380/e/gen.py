import random

# N = random.randint(a, b)  # a<=N<=b のNを返す
N = 1000
Q = 5

A = [0] * N
print(N, Q + N)
for qi in range(Q):
    x = random.randint(1, N)
    c = random.randint(1, N)
    print(1, x, c)
for c in range(N):
    print(2, c + 1)
