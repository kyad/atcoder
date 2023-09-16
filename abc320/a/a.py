def main():
    A, B = map(int, input().split())
    ans = A ** B + B ** A
    print(ans)

if __name__ == "__main__":
    main()
