#import pypyjit
import sys

#pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    x, y = map(int, input().split())
    if x == y:
        ans = x
    else:
        ans = 3 - x - y
    print(ans)

if __name__ == "__main__":
    main()
