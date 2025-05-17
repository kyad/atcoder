# import pypyjit
import sys

# pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    value = 1
    threshold = 1
    for k in range(K):
        threshold *= 10
    for i in range(N):
        value *= A[i]
        if value >= threshold:
            value = 1
    print(value)


if __name__ == "__main__":
    main()
