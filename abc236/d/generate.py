N = 8
print(N)
M = 2 * N
for i in range(M):
    for j in range(i + 1, M):
        print("1 ", end="" if j == M - 1 else " ")
    print()
