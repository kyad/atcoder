V, A, B, C = map(int, input().split())
V = V % (A + B + C)
if V - A < 0:
    ans = 'F'
elif V - A - B < 0:
    ans = 'M'
else:
    ans = 'T'
print(ans)
