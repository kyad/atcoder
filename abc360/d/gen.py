import random

N = random.randint(2, 7)  # a<=N<=b のNを返す
T = random.randint(1, 10)  # a<=N<=b のNを返す
#T = random.randint(1, 10**9)  # a<=N<=b のNを返す

lis = list(range(-10, 10))  # 1, 2, .., N
#lis = list(range(-10**9, 10**9, 10**8))  # 1, 2, .., N
X = random.sample(lis, k=N)  # 配列から重複を許さずにk個取る

alphabet = ''.join([chr(ord('0') + i) for i in range(2)])  # 数字
S = ''.join(random.choices(alphabet, k=N))  # ランダムな文字列

print(N, T)
print(S)
print(*X)
