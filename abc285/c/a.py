S = input()
L = len(S)
p = 26 * (26 **(L - 1) - 1) // 25
q = 0
for i in range(L):
    q *= 26
    c = ord(S[i])
    q += (c - ord('A'))
print(p + q + 1)
