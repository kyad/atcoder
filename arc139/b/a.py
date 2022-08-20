# https://atcoder.jp/contests/arc139/tasks/arc139_b

import math

def testcase():
    N, A, B, X, Y, Z = map(int, input().split())

    # A増やす方が、B増やすよりもコスパが良いとする。
    if Y * B > A * Z:
        A, B = B, A
        Y, Z = Z, Y
    ans = 0

    # 前処理
    Y = min(Y, A * X)
    Z = min(Z, B * X)

    a = N // A
    b = A - 1

    def solve1():
        ans = math.inf
        for y in range(a + 1):
            z = (N - y * A) // B
            x = (N - y * A) % B
            now = X * x + Y * y + Z * z
            ans = min(ans, now)
        return ans

    def solve2():
        ans = math.inf
        for z in range(b + 1):
            if N - z * B < 0:
                continue
            y = (N - z * B) // A
            x = (N - z * B) % A
            now = X * x + Y * y + Z * z
            ans = min(ans, now)
        return ans

    if a < b:
        ans += solve1()
    else:
        ans += solve2()
    print(ans)

if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        testcase()
