N, M, X, T, D = map(int, input().split())
ans = T - X * D + D * min(M, X)
print(ans)
