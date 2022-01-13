# https://atcoder.jp/contests/abc208/tasks/abc208_a

A, B = map(int, input().split())
min = A
max = A * 6
print('Yes' if min <= B <= max else 'No')
