import random

N = random.randint(3, 6)  # a<=N<=b のNを返す
l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
s = random.choices(l, k=N)
S = ''.join(s)  # ランダムな文字列
t = [x for x in s]
random.shuffle(t)
T = ''.join(t)

print(N)
print(S)
print(T)
