import random

N = 2*10**5
Q = 2*10**5

# N = random.randint(a, b)  # a<=N<=b のNを返す
# l = list(range(1, N + 1))  # 1, 2, .., N
# l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
# A = sorted(random.sample(word, 3))  # 重複を許さずにk個取ってソートする
# A = random.choices(l, k=k)  # 配列から重複を許してk個取る
# r = random.random()  # 0以上1未満の浮動小数点数

# alphabet = ''.join([chr(ord('a') + i) for i in range(26)])  # 英小文字全て
# alphabet = ''.join([chr(ord('0') + i) for i in range(10)])  # 数字
# S = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列

A = [0] * N
for n in range(N):
    A[n] = random.randint(1, N)  # a<=N<=b のNを返す

print(N, Q)
print(*A)
for q in range(Q):
    a = 0
    b = 0
    while a == b:
        a = random.randint(1, N)  # a<=N<=b のNを返す
        b = random.randint(1, N)  # a<=N<=b のNを返す
    print(a, b)
