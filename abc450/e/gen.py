import random

# N = random.randint(a, b)  # a<=N<=b のNを返す
# l = list(range(1, N + 1))  # 1, 2, .., N
# l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
# A = sorted(random.sample(word, 3))  # 重複を許さずにk個取ってソートする
# A = random.choices(l, k=k)  # 配列から重複を許してk個取る
# r = random.random()  # 0以上1未満の浮動小数点数

# alphabet = ''.join([chr(ord('a') + i) for i in range(26)])  # 英小文字全て
alphabet = ''.join([chr(ord('a') + i) for i in range(3)])
# alphabet = ''.join([chr(ord('0') + i) for i in range(10)])  # 数字
len = random.randint(1, 3)
X = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列
len = random.randint(1, 3)
Y = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列
print(X, Y)
Q = 1
print(Q)
L = random.randint(1, 5)
R = random.randint(1, 5)
if L > R:
    L, R = R, L
a = random.randint(0, 2)
C = chr(ord('a') + a)
print(L, R, C)
