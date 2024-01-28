import re
import sys
sys.set_int_max_str_digits(0)


def main():
    S = input()
    pattern = r'^A*B*C*$'
    result = re.match(pattern, S)
    if result:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
