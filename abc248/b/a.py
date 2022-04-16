A, B, K = map(int, input().split())
ans = 0
while True:
    if A >= B:
        break
    A *= K
    ans += 1
print(ans)
