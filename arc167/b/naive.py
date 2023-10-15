MOD = 998244353
def main():
    A, B = map(int, input().split())
    x = A**B
    prod = 1
    for a in range(1, x + 1):
        if x % a == 0:
            prod *= a
    ans = 0
    while prod > 0:
        if prod % A == 0:
            prod //= A
            ans += 1
            ans %= MOD
        else:
            break
    print(ans)

if __name__ == "__main__":
    main()
