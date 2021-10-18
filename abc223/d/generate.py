import random
N = random.randint(2, 10)
M = random.randint(1, 10)
print(N)
print(M)
for m in range(M):
    l = random.sample(range(1, N + 1), 2)
    print(l[0], l[1])
