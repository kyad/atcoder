import random

H = random.randint(4, 5)  # a<=N<=b のHを返す
W = random.randint(4, 5)  # a<=N<=b のWを返す

print(H, W)
alphabet = ''.join([chr(ord('a') + i) for i in range(3)])  # 英小文字全て
for y in range(H):
    S = ''.join(random.choices(alphabet, k=W))  # ランダムな文字列
    print(S)
