# https://atcoder.jp/contests/typical90/tasks/typical90_g

n = int(input())
a = list(map(int, input().split()))
q = int(input())
a.sort()

def bisection(b):
    left = 0
    right = len(a) - 1
    while right - left > 1:
        middle = (left + right) // 2
        if b < a[middle]:
            right = middle
        else:
            left = middle
    l = a[left]
    r = a[right]
    return min(abs(b - l), abs(r - b))

for i in range(q):
    b = int(input())
    print(bisection(b))
