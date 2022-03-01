import random

#random.seed(0)

T = 1
print(T)
N = 3
X = [0] * N
Y = [0] * N
M = 0
for n in range(N):
    X[n] = random.randint(-4, 4)
    Y[n] = random.randint(1, 3)
    M += Y[n]
print(N, M)
for n in range(N):
    print(X[n], Y[n])
