x = input()
if x[0] == x[1] and x[0] == x[2] and x[0] == x[3]:
    print("Weak")
    exit(0)
a = [0] * 4
for i in range(4):
    a[i] = ord(x[i]) - ord('0')
count = 3
for i in range(3):
    if (a[i + 1] - a[i] + 10) % 10 == 1:
        count -= 1
if count == 0:
    print("Weak")
else:
    print("Strong")
