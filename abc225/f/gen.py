import random

N = 7  # <=7
K = random.randint(1, 7)
print(N, K)

alphabet = "abcde"
        
for n in range(N):
    len = random.randint(1, 50)
    S = ''.join(random.choices(alphabet, k=len))
    print(S)
