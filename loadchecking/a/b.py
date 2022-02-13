import random
a = list(range(1, 21))
random.shuffle(a)
for i in range(20):
    print(a[i])
