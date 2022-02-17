# https://atcoder.jp/contests/abc207/tasks/abc207_a

A, B, C = map(int, input().split())
print(max(A + B, B + C, C + A))
