import random

N = random.randint(1, 7)  # a<=N<=b のNを返す
X = random.randint(1, 10)  # a<=N<=b のNを返す
Y = random.randint(1, 10)  # a<=N<=b のNを返す
print(N, X, Y)
for i in range(N):
    A = random.randint(1, 5)  # a<=N<=b のNを返す
    B = random.randint(1, 5)  # a<=N<=b のNを返す
    print(A, B)
