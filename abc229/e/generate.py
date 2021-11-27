import random
N = 5
M = 10
array = []
for u in range(N - 1):
    for v in range(u + 1, N):
        array.append((u, v))
l = random.sample(array, M)
print(N, M)
for i in l:
    print(i[0]+1, i[1]+1)
