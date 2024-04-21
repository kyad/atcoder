import sys
sys.set_int_max_str_digits(0)


def ceildiv(a, b):
    return (a + b - 1) // b


def naive(N, M, K):
    ans = pow(2, N) % (pow(2, M)-pow(2, K))
    ans %= 10
    return ans


def testcase():
    N, M, K = map(int, input().split())
    ans = naive(N, M, K)
    print(ans)


def main():
    T = int(input())
    for t in range(T):
        testcase()


if __name__ == "__main__":
    main()
