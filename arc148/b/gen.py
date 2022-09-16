import random

N = random.randint(5, 10)  # a<=N<=b のNを返す

alphabet = 'dp'
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列

print(N)
print(S)
