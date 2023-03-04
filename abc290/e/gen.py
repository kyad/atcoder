import random

N = random.randint(4, 5)  # a<=N<=b のNを返す
l = list(range(1, N + 1))  # 1, 2, .., N
A = random.choices(l, k=N)  # 配列から重複を許してk個取る
print(N)
print(*A)
