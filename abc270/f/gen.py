import random

N = random.randint(5, 7)
X = [random.randint(1, 10) for i in range(N)]
Y = [random.randint(1, 10) for i in range(N)]

M = random.randint(5, 7)
Z = []
for m in range(M):
    l = list(range(1, N + 1))
    A, B = random.sample(l, k=2)
    cost = random.randint(1, 10)
    Z.append([A, B, cost])
Z = sorted(Z)
M = len(Z)

print(N, len(Z))
print(*X, sep=' ')
print(*Y, sep=' ')
for m in range(M):
    print(*Z[m], sep=' ')
