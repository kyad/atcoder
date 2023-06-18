import random

N = random.randint(2, 10)  # a<=N<=b のNを返す
l = list(range(1, N + 1))  # 1, 2, .., N
random.shuffle(l)

print(N)
print(*l)
