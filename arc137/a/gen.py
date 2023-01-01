import random

a = 0
b = 0
while a == b:
    a = random.randint(1, 1000)
    b = random.randint(1, 1000)
L = min(a, b);
R = max(a, b);
print(L, R)
