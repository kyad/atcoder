import sys
sys.set_int_max_str_digits(0)


def ceildiv(a, b):
    return (a + b - 1) // b


def f(N, M, K):
    #print(N, M, K)
    if N >= M - 1 and M == K + 1:
        #print("Case 1")
        ans = 0
    elif N < M:
        #print("Case 2")
        # 商が0
        ans = pow(2, N, 10)
    else:
        #print("Case 3")
        ans = pow(2, K, 10)
    return ans


def testcase():
    N, M, K = map(int, input().split())
    if N > M:
        q = ceildiv(N - M, M - K)
        N -= q * (M - K)
        assert N > 0
    ans = f(N, M, K)
    print(ans)


def main():
    T = int(input())
    for t in range(T):
        testcase()


if __name__ == "__main__":
    main()
