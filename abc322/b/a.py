def main():
    N, M = map(int, input().split())
    S = input()
    T = input()
    ans = 3
    if T.startswith(S) and T.endswith(S):
        ans = 0
    elif T.startswith(S):
        ans = 1
    elif T.endswith(S):
        ans = 2
    print(ans)

if __name__ == "__main__":
    main()
