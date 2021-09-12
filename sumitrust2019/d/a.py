# https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
# Python3: TLE
# PyPy3: AC

N = int(input())
S = input()
count = [0] * 1000
for num in range(1000):
    i = 0
    j = 0
    num_str = '{:03}'.format(num)
    while True:
        c = num_str[i]
        if c == S[j]:
            i += 1
        j += 1
        if i == 3:
            count[num] = 1
            break
        if j >= N:
            break
print(sum(count))
