N = int(input())
dict = {}
for n in range(N):
    S = input()
    if S in dict:
        dict[S] = dict[S] + 1
    else:
        dict[S] = 1
best = -1
ans = ''
for name, value in dict.items():
    if value > best:
        best = value
        ans = name
print(ans)
