n = int(input())
t = []
x = []
y = []
for i in range(n):
    tt, xx, yy = map(int, input().split())
    t.append(tt)
    x.append(xx)
    y.append(yy)
t0 = 0
x0 = 0
y0 = 0
for i in range(n):
    tt = t[i] - t0
    xx = abs(x[i] - x0)
    yy = abs(y[i] - y0)
    temp = tt - (xx + yy)
    if temp >= 0 and temp % 2 == 0:
        t0 = t[i]
        x0 = x[i]
        y0 = y[i]
    else:
        print('No')
        exit(0)
print('Yes')
