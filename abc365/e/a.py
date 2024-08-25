import pypyjit
import sys

pypyjit.set_param("max_unroll_recursion=-1")
sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    N = int(input())
    A = list(map(int, input().split()))
    A.insert(0, 0)  # 冒頭に入れて1-indexedにする
    # 累積xor
    S = [0] * (N + 1)
    for i in range(N + 1):
        S[i] = S[i - 1] ^ A[i]
    ans = 0
    for k in range(32):  # ビット単位で考える
        zeros, ones = 0, 0  # S[2]..S[N]のうち0, 1の個数
        for i in range(2, N + 1):
            if S[i] >> k & 1:
                ones += 1
            else:
                zeros += 1
        now = 0
        for i in range(0, N - 1):
            if S[i] >> k & 1:
                now += zeros << k
            else:
                now += ones << k
            # zeros, onesの更新
            if S[i + 2] >> k & 1:
                ones -= 1
            else:
                zeros -= 1
        ans += now
    print(ans)


if __name__ == "__main__":
    main()
