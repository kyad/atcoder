import random

N = random.randint(8, 11)
l = list(range(N))
random.shuffle(l)

l = [i + 1 for i in l]

print(N)
print(*l, sep=' ')
