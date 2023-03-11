A, X, M = map(int, input().split())

if A == 1:
    ans = X % M
elif M == 1:
    ans = 0
else:
    ans = ( (A ** X - 1) // (A - 1) ) % M
print(ans)
