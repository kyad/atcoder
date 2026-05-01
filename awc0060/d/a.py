# import pypyjit
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
    N2 = 1 << N
    INF = 100
    ans = INF
    for bit in range(N2):
        ps = 1
        qs = 1
        now = 0
        for i in range(N):
            if (bit >> i) & 1 == 1:
                ps *= P[i]
                qs *= Q[i]
                now += 1
        if now >= 2 and ps == qs:
            ans = min(ans, now)
    if ans == INF:
        ans = -1
    print(ans)


if __name__ == "__main__":
    main()
