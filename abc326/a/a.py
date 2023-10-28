import sys
sys.set_int_max_str_digits(0)


def main():
    X, Y = map(int, input().split())
    ans = False
    if X <= Y:
        if Y - X <= 2:
            ans = True
    else:
        if X - Y <= 3:
            ans = True
    if ans == True:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
