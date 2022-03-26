A, B, C, D = map(int, input().split())
t = A * 100 + B
a = C * 100 + D
if t <= a:
    ans = "Takahashi"
else:
    ans = "Aoki"
print(ans)
