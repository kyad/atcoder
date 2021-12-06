import random
N = 10
S = ""
for n in range(N):
    r = random.randint(1, 2)
    if r == 1:
        S += '.'
    else:
        S += 'X'
print(S)
K = random.randint(1, 5)
print(K)
