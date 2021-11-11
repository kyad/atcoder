import math
a, b, x = map(int, input().split())
if x <= a * a * b / 2:
    ans = math.atan(a * b * b / (2 * x))
else:
    ans = math.atan(2 * b / a - (2 * x) / (a * a * a))
ans = math.degrees(ans)
print('{:.9f}'.format(ans))
