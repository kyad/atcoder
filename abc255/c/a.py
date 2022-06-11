X, A, D, N = map(int, input().split())

if D == 0:
    print(abs(A - X))
    exit(0)

if D < 0:
    X = -X
    A = -A
    D = -D

R = A + (N - 1) * D

if X < A:
    print(A - X)
    exit(0)
elif X > R:
    print(X - R)
    exit(0)

left = A + ( (X - A) // D ) * D
a = X - left
b = D - a
ans = min(a, b)

print(ans)
