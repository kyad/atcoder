S = input()
T = input()
K = (ord(T[0]) - ord(S[0]) + 26) % 26
ok = True
for i in range(1, len(S)):
    temp = (ord(T[i]) - ord(S[i]) + 26) % 26
    if K != temp:
        ok = False
print('Yes' if ok else 'No')
