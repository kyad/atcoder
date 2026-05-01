# import pypyjit
import math
import sys

# pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    N = int(input())
    P = [0] * N
    Q = [0] * N
    for i in range(N):
        P[i], Q[i] = map(int, input().split())

    A = P[0]
    B = Q[0]
    for i in range(1, N):
        lq = math.lcm(B, Q[i])
        AA = A * (lq // B)
        PP = P[i] * (lq // Q[i])
        lpp = math.lcm(AA, PP)
        nA = lpp * A
        nB = AA * B
        g = math.gcd(nA, nB)
        A = nA // g
        B = nB // g
    print(A, B)


if __name__ == "__main__":
    main()
