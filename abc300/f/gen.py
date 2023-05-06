import random

N = random.randint(3, 8)  # a<=N<=b のNを返す
M = 1
X = random.randint(1, N)
K = random.randint(1, X)
S = [ 'o' for i in range(N - X) ] + [ 'x' for i in range(X) ]
random.shuffle(S)
print(N, M, K)
print(''.join(S))
