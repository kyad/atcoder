import random

N = random.randint(5, 10)  # a<=N<=b のNを返す
word = [chr(ord('0') + i) for i in range(2)]

S = ''.join(random.choices(word, k=N))  # ランダムな文字列
T = ''.join(random.choices(word, k=N))  # ランダムな文字列

print(N)
print(S)
print(T)
