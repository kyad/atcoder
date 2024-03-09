import sys
sys.set_int_max_str_digits(0)


def main():
    A = input().split('|')
    ans = A[0] + A[2]
    print(ans)

if __name__ == "__main__":
    main()
