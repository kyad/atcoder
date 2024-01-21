import random

N = 100

alphabet = ''.join([chr(ord('A') + i) for i in range(2)])
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列
T = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列

print(N)
print(S)
print(T)
