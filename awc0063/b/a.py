# import pypyjit
import sys
import math

# pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    N, M = map(int, input().split())
    P = list(map(int, input().split()))
    ans = "Yes"
    now = P[0]
    if now > M:
        ans = "No"
    for i in range(1, N):
        now = math.lcm(now, P[i])
        if now > M:
            ans = "No"
            break
    print(ans)


if __name__ == "__main__":
    main()
