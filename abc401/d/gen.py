import random

# N = random.randint(a, b)  # a<=N<=b のNを返す
N = 7
K = 3
alphabet = '.o??'
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列

print(N, K)
print(S)
