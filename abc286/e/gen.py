import random

N = 300


# N = random.randint(a, b)  # a<=N<=b のNを返す
# l = list(range(1, N + 1))  # 1, 2, .., N
# l = [chr(ord('a') + i) for i in range(5)]  # a, b, c, d, e
# A = random.sample(l, k=k)  # 配列から重複を許さずにk個取る
# A = sorted(random.sample(word, 3))  # 重複を許さずにk個取ってソートする
# A = random.choices(l, k=k)  # 配列から重複を許してk個取る
# r = random.random()  # 0以上1未満の浮動小数点数

# l = ''.join([chr(ord('a') + i) for i in range(26)])  # アルファベット全て
# S = ''.join(random.choices(alphabet, k=len))  # ランダムな文字列

A = [0] * N
S = [""] * N
for n in range(N):
    A[n] = random.randint(1, 1000000000)
    now = [0] * N
    for j in range(N):
        r = random.randint(0, 1)
        if r == 0:
            now[j] = 'Y'
        else:
            now[j] = 'N'
    S[n] = ''.join(now)

    

print(N)
print(*A)
for n in range(N):
    print(S[n])

Q = N * (N - 1)
print(Q)

for U in range(1, N + 1):
    for V in range(1, N + 1):
        if U == V:
            continue
        print(U, V)



exit
Q = 1
print(Q)
for q in range(Q):
    U, V = random.sample(range(1, N + 1), k=2)  # 配列から重複を許さずにk個取る
    print(U, V)
    
