# https://atcoder.jp/contests/typical90/tasks/typical90_b

n = int(input())
if n % 2 == 1:
    print('')
    exit()
p = [[] for i in range(21)]
p[2].append('()')
for i in range(4, n + 1, 2):
    for j in range(len(p[i - 2])):
        p[i].append('(' + p[i - 2][j] + ')')
    for left in range(2, n - 2 + 1, 2):
        right = i - left
        for j in range(len(p[left])):
            for k in range(len(p[right])):
                p[i].append(p[left][j] + p[right][k])
    p[i] = sorted(list(set(p[i])))
for a in p[n]:
    print(a)
