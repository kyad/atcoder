import random

# N = random.randint(a, b)  # a<=N<=b のNを返す
# l = list(range(4, 6))
word = [chr(ord('A') + i) for i in range(3)]
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
S = random.choices(word, k=4)  # 配列から重複を許してk個取る

# l = ''.join([chr(ord('a') + i) for i in range(26)])
# S = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列
# a = sorted(random.sample(word, 3))  # 重複しないように選ぶ

N = 10
for n in range(N):
    word = [chr(ord('A') + i) for i in range(3)]
    S = random.choices(word, k=6)  # 配列から重複を許してk個取る
    print(''.join(S))
