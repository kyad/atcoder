import random

N = random.randint(3, 5)
M = random.randint(4, 6)
P = [i + 1 for i in range(N)]
random.shuffle(P)

print(N, M)
print(' '.join(map(str, P)))
