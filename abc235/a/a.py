A = int(input())
a = A // 100
b = (A - a * 100) // 10
c = A % 10
x = a * 100 + b * 10 + c
y = b * 100 + c * 10 + a
z = c * 100 + a * 10 + b
print(x + y + z)
