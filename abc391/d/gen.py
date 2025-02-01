import random

N = 5
W = 3
print(N, W)
H = 5
X = [0] * N
Y = [0] * N
for i in range(N):
    while True:
        x = random.randint(1, W)
        y = random.randint(1, H)
        ok = True
        for j in range(i):
            if X[j] == x and Y[j] == y:
                ok = False
                break
        if ok:
            break
    X[i] = x
    Y[i] = y

for i in range(N):
    print(X[i], Y[i])

Q = 5
print(Q)
for q in range(Q):
    T = random.randint(1, H)
    A = random.randint(1, N)
    print(T, A)
