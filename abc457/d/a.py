# import pypyjit
import sys

# pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def ceildiv(a, b):
    return (a + b - 1) // b


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    def check(X):
        C = K
        for i in range(N):
            if A[i] >= X:
                continue
            count = ceildiv(X - A[i], i + 1)
            C -= count
            if C < 0:
                return False
        return True
    left = 0  # OK
    right = 2 * (10**18) + 1  # NG
    while right - left > 1:
        mid = (left + right) // 2
        if check(mid) == True:
            left = mid
        else:
            right = mid
    ans = left
    print(ans)


if __name__ == "__main__":
    main()
