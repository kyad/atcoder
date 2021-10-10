N = 1000
M = 100
K = 10000
print(N, M, K)
A = [1 if i % 2 == 0 else 1000 for i in range(M)]
print(' '.join(map(str, A)))
for n in range(N - 1):
    print(n + 1, n + 2)
