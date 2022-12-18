import random

N = random.randint(3, 5)  # a<=N<=b のNを返す
U = []
V = []
for u in range(1, N + 1):
    for v in range(u + 1, N + 1):
         r = random.random()  # 0以上1未満の浮動小数点数
         if r < 0.5:
             U.append(u)
             V.append(v)
M = len(U)
print(N, M)
for u, v in zip(U, V):
    print(u, v)
