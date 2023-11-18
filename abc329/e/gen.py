import random

N = random.randint(1, 100)  # a<=N<=b のNを返す
M = random.randint(1, min(N, 5))  # a<=N<=b のNを返す
alphabet = ''.join([chr(ord('A') + i) for i in range(26)])  # 数字
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列
T = ''.join(random.choices(alphabet, k=M))  # ランダムな文字列

print(N, M)
print(S)
print(T)
