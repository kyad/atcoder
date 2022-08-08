# https://atcoder.jp/contests/arc142/tasks/arc142_b

N = int(input())

A = [ [ i + 1 for i in range(0 + j * N, N + j * N) ] for j in range(N) ]

for i in range(N):
    for k in range(N // 2):
        A[i][2 * k], A[i][2 * k + 1] = A[i][2 * k + 1], A[i][2 * k]

for i in range(N):
    print(*A[i], sep=' ')
