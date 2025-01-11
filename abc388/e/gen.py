import random

N = random.randint(6, 8)  # a<=N<=b のNを返す
A = random.choices(range(1, 20), k=N)  # 配列から重複を許してk個取る
A = sorted(A)

print(N)
print(*A)
