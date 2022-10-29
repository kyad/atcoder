N = int(input())
H = list(map(int, input().split()))
ans = 0
mx = -1
for i in range(N):
    if H[i] > mx:
        mx = H[i]
        ans = i + 1
print(ans)
