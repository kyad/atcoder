import random
N = 2000
K = 2000
S = [chr(ord('a') + random.randint(0, 25)) for i in range(N)]

print(N, K)
print(''.join(S))
