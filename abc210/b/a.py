# https://atcoder.jp/contests/abc210/tasks/abc210_b

import numpy as np

N = int(input())
S = input()
a = np.zeros(N)
for i, c in enumerate(S):
    if c == '0':
        a[i] = 0
    else:
        a[i] = 1
for i in range (N):
    if a[i] == 1:
        if i % 2 == 0:
            print('Takahashi')
        else:
            print('Aoki')
        break
