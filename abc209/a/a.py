# https://atcoder.jp/contests/abc209/tasks/abc209_a

A, B = map(int, input().split())
if (A > B):
    print(0)
else:
    print(B - A + 1)
