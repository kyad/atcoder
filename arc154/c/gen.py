import random

T = random.randint(10, 10)  # a<=N<=b のNを返す
print(T)
for t in range(T):
    N = random.randint(5, 8)  # a<=N<=b のNを返す
    #l = list(range(1, 4+1))
    l = list(range(1, 2+1))
    A = random.choices(l, k=N)  # 配列から重複を許してk個取る
    B = random.choices(l, k=N)  # 配列から重複を許してk個取る
    print(N)
    print(*A)
    print(*B)
