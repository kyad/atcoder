import random

print(1)
H = 4
W = 4
print(H, W)
alphabet = '.#'
for y in range(H):
    S = ''.join(random.choices(alphabet, k=W))  # ランダムな文字列
    print(S)
