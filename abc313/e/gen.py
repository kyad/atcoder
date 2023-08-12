import random

S = ''

#alphabet = ''.join([chr(ord('0') + i) for i in range(1, 10)])  # 12..9
alphabet = ''.join([chr(ord('0') + i) for i in range(1, 3)])  # 12..9

#for n in range(random.randint(1, 4)):
for n in range(random.randint(1, 2)):
    p = random.choices(alphabet, k=1)
    S += p[0]
    q = random.randint(1, 2)
    for i in range(q):
        S += "1"

N = len(S)

print(N)
print(S)
