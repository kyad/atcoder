import time
import random
a = list(range(1, 21))
s = int(time.time() - 3600)
random.seed(s)
random.shuffle(a)
for i in range(20):
    print(a[i])
