#primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
A = [4, 9, 5, 7, 11, 13, 17, 19, 23]
sum = 0
mul = 1
for a in A:
    sum += a
    mul *= a
print(sum, mul)
