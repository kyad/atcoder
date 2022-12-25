import random

#N = random.randint(4, 5)  # a<=N<=b のNを返す
N = 4
# l = list(range(1, N + 1))  # 1, 2, .., N
# l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
# A = sorted(random.sample(word, 3))  # 重複を許さずにk個取ってソートする
# A = random.choices(l, k=k)  # 配列から重複を許してk個取る
# r = random.random()  # 0以上1未満の浮動小数点数

alphabet = ''.join([chr(ord('a') + i) for i in range(26)])  # アルファベット全て
S = random.choices(alphabet, k=N)
for n in range(N):
    r = random.random()  # 0以上1未満の浮動小数点数
    if r < 0.3:
        S[n] = '?'
S = ''.join(S)

print(N)
print(S)
