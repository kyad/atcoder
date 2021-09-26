N = 10 ** 5
print(N)
for i in range(N):
    print(i % 10, end='\n' if i == N - 1 else ' ')
