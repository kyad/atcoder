import random

N1 = random.randint(3, 5)  # a<=N<=b のNを返す
V1 = []
L1 = []
L = 0
for n1 in range(N1):
    v1 = random.randint(13, 15)
    l1 = random.randint(3, 5)
    V1.append(v1)
    L1.append(l1)
    L += l1

V2 = []
L2 = []
l2_sum = 0
while l2_sum != L:
    v2 = random.randint(13, 15)
    l2 = random.randint(3, 5)
    l2 = min(l2, L - l2_sum)
    V2.append(v2)
    L2.append(l2)
    l2_sum += l2
N2 = len(V2)
print(L, N1, N2)
for n1 in range(N1):
    print(V1[n1], L1[n1])
for n2 in range(N2):
    print(V2[n2], L2[n2])
        
    


# l = list(range(1, N + 1))  # 1, 2, .., N
# l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
# A = sorted(random.sample(word, 3))  # 重複を許さずにk個取ってソートする
# A = random.choices(l, k=k)  # 配列から重複を許してk個取る
# r = random.random()  # 0以上1未満の浮動小数点数

# l = ''.join([chr(ord('a') + i) for i in range(26)])  # アルファベット全て
# S = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列

# A = [0] * N
# for n in range(N):
#     A[n] = random.randint(1, 10)  # a<=N<=b のNを返す

# print(N)
# print(*A)
