N, K = map(int, input().split())
R = list(map(int, input().split()))
A = [0] * N


# n文字目以降を列挙する
def f(n):
    if n == N:  # 終了条件
        if sum(A) % K == 0:
            print(*A)
        return
    # n文字目にrを置く
    for r in range(1, R[n] + 1):
        A[n] = r
        f(n + 1)  # n+1文字目以降を置く


f(0)
