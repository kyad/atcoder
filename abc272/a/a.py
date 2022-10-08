N = int(input())
A = list(map(int, input().split()))
sum = 0
for n in range(N):
    sum += A[n]
print(sum)
