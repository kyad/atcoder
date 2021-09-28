N = 500
M = 2 * 10 ** 6
Q = 10 ** 6
print(N, M, Q)
for m in range(M):
    print(m % (N - 1) + 1, m % (N - 1) + 2)
for i in range(Q):
    print(i % (N - 1) + 1, i % (N - 1) + 2)
