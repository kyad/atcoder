n, a, b = map(int, input().split())
ans = 0
for i in range(1, n + 1):
    temp = i
    sum = 0
    while True:
        if temp < 10:
            sum += temp
            break
        else:
            sum += (temp % 10)
            temp = temp // 10
    if a <= sum <= b:
        ans += i
print(ans)
