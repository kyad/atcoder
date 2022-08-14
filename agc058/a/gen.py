import random
#N = 3
N = 10
l = [ i + 1 for i in range(N * 2) ]
random.shuffle(l)

print(N)
print(*l, sep=' ')
