import random

N = 2*10**5
M = 5
alphabet = ''.join([chr(ord('A') + i) for i in range(1)])  # 数字
alphabet2 = ''.join([chr(ord('B') + i) for i in range(1)])  # 数字
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列
T = ''.join(random.choices(alphabet2, k=M))  # ランダムな文字列

print(N, M)
print(S)
print(T)
