N = int(input())
P = list(map(int, input().split()))

S = int(input())
for s in range(S):
    x, i = input().split()
    i = int(i)
    i -= 1
    if x == 'A':
        ni = i + 1
    else:
        ni = i + 2
    P[i], P[ni] = P[ni], P[i]


ans = [i + 1 for i in range(N)]

if P != ans:
    print(P)
    exit(1)
exit(0)
