import random

alphabet = '01?'
#alphabet = ''.join(['0', '1', '?'])

T = 1
N = 5
K = random.randint(1, N)  # a<=N<=b のNを返す
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列
print(T)

print(N, K)
print(S)
