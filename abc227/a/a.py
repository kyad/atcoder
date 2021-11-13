N, K, A = map(int, input().split())
A -= 1
K -= 1
print((K + A) % N + 1)
