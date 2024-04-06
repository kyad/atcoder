import random

H = 200
W = 200
alphabet = '...#'
A = []
for y in range(H):
    now = []
    for x in range(W):
        now.append(random.choices(alphabet, k=1))
    A.append(now)
A[1][1] = 'S'
A[2][3] = 'T'

print(H, W)
for y in range(H):
    for x in range(W):
        print(A[y][x][0], end='')
    print()

Nmax=300
N = random.randint(1, Nmax)  # a<=N<=b のNを返す
print(N)
for n in range(N):
    R = random.randint(1, H)  # a<=N<=b のNを返す
    C = random.randint(1, W)  # a<=N<=b のNを返す
    E = random.randint(1, W * H)
    print(R, C, E)
