import random

N = random.randint(5, 5)  # a<=N<=b のNを返す
K = random.randint(3, N)  # a<=N<=b のNを返す
## [1, ..., N]のランダムな順列
P = list(range(1, N + 1))  # 1, 2, .., N
random.shuffle(P)  # Aをシャッフルする

print(N, K)
print(*P)
