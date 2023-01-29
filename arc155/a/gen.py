import random

T = 1
N = 3
K = random.randint(10**10, 10**17)  # a<=N<=b のNを返す

l = ''.join([chr(ord('a') + i) for i in range(26)])  # アルファベット全て
S = ''.join(random.choices(l, k=N))  # ランダムな文字列

print(T)
print(N, K)
print(S)
