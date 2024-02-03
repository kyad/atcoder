import sys
sys.set_int_max_str_digits(0)


def main():
    S = input()
    ans = S.split('.')[-1]
    print(ans)


if __name__ == "__main__":
    main()
