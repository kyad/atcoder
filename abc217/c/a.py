N = int(input())
p = list(map(int, input().split()))
for n in range(N):
    p[n] -= 1
q = [-1] * N
for n in range(N):
    q[p[n]] = n
for n in range(N):
    q[n] += 1
print(' '.join([str(i) for i in q]))
