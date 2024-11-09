import sys

sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    N = int(input())
    S = input()
    ans = 0
    prev = 0
    for i in range(N):
        d = ord(S[i]) - ord('0')
        now = prev * 10 + d * (i + 1)
        prev = now
        ans += now
    print(ans)


if __name__ == "__main__":
    main()
