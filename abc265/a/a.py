X, Y, N = map(int, input().split())
ans = X * N
r = N // 3
q = N % 3
ans = min(ans, r * Y + X * q)
print(ans)
