def solve(A, B, C, X):
    count = X // (A + C)
    ans = A * B * count
    t = X - (A + C) * count
    t = min(t, A)
    ans += B * t
    return ans
   
A, B, C, D, E, F, X = map(int, input().split())
takahashi = solve(A, B, C, X)
aoki = solve(D, E, F, X)
if takahashi > aoki:
    print('Takahashi')
elif takahashi < aoki:
    print('Aoki')
else:
    print('Draw')
