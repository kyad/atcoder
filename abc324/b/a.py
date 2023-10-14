def main():
    N = int(input())
    for x in range(0, 61):
        for y in range(0, 39):
            now = 2**x * 3**y
            if N == now:
                print("Yes")
                return
    print("No")
    return

if __name__ == "__main__":
    main()
