# https://atcoder.jp/contests/abc149/tasks/abc149_b

A, B, K = map(int, input().split())
C = min(K, A)
print(A - C, max(B - (K - C), 0))
