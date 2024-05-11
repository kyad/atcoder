import random

# N = random.randint(a, b)  # a<=N<=b のNを返す
N = 5
alphabet = ''.join([chr(ord('a') + i) for i in range(3)])

print(N)
S = []
for n in range(N):
    len = random.randint(2, 10)  # a<=N<=b のNを返す
    s = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列
    S.append(s)
print(*S)
