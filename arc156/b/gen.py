import random

#N=2*10**5 #NG
#K=2*10**5 #NG
N=1*10**5 #OK
K=1*10**5 #OK
l = list(range(0, 1000))  # 1, 2, .., N
A = random.choices(l, k=N)  # 配列から重複を許してk個取る

print(N, K)
print(*A)
