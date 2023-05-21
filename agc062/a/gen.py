import random

N = random.randint(2, 10)  # a<=N<=b のNを返す
# l = list(range(1, N + 1))  # 1, 2, .., N
# l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
# A = sorted(random.sample(word, 3))  # 重複を許さずにk個取ってソートする
# A = random.choices(l, k=k)  # 配列から重複を許してk個取る
# r = random.random()  # 0以上1未満の浮動小数点数

# l = ''.join([chr(ord('a') + i) for i in range(26)])  # アルファベット全て
l = [chr(ord('A') + i) for i in range(2)]
S = ''.join(random.choices(l, k=N))  # ランダムな文字列
print(1)
print(N)
print(S)

# A = [0] * N
# for n in range(N):
#     A[n] = random.randint(1, 10)  # a<=N<=b のNを返す

# print(N)
# print(*A)
