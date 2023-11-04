import sys
sys.set_int_max_str_digits(0)


def main():
    B = int(input())
    A = 1
    while True:
        if A ** A == B:
            print(A)
            return
        if A ** A > B:
            break
        A += 1
    print(-1)


if __name__ == "__main__":
    main()
