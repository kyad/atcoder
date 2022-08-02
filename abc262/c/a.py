N = int(input())
A = list(map(int, input().split()))
A = [ a - 1 for a in A ]

same = 0
for n in range(N):
    if n == A[n]:
        same += 1

ans1 = 0
for n in range(N):
    if n == A[n]:
        ans1 += (same - 1)
ans1 //= 2

ans2 = 0
for n in range(N):
    if n != A[n]:
        if n == A[A[n]]:
            ans2 += 1
ans2 //= 2

print(ans1 + ans2)
