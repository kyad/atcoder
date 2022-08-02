N, M = map(int, input().split())
st = set()
for m in range(M):
    U, V = map(int, input().split())
    U -= 1
    V -= 1
    mn = min(U, V)
    mx = max(U, V)
    st.add((mn, mx))

ans = 0
for a in range(N):
    for b in range(a, N):
        for c in range(b, N):
            if (a, b) in st and (b, c) in st and (a, c) in st:
                ans += 1
print(ans)
