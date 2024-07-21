def main():
    N, M, X = map(int, input().split())
    C = [0] * N
    A = [[0] * M for i in range(N)]
    for i in range(N):
        C[i], *A[i] = map(int, input().split())
    N2 = 1 << N  # 2^N
    INF = 4 * 10**18
    ans = INF
    # ビット全探索
    for bit in range(N2):
        U = [0] * M  # U[j]: j番目のアルゴリズムの理解度
        now = 0  # 書籍購入費用
        for i in range(N):
            if bit >> i & 1:
                now += C[i]
                for j in range(M):
                    U[j] += A[i][j]
        ok = True
        for j in range(M):
            if U[j] < X:
                ok = False
        if ok:
            ans = min(ans, now)
    if ans == INF:
        ans = -1
    print(ans)


if __name__ == "__main__":
    main()
