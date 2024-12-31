import sys

sys.set_int_max_str_digits(0)
sys.setrecursionlimit(10**6)


def main():
    N, Q = map(int, input().split())
    pos = [0, 1]  # 左手, 右手の位置
    ans = 0
    for q in range(Q):
        H, T = input().split()
        T = int(T)
        T -= 1
        if H == "L":
            h = 0
        else:
            h = 1
        INF = 100000

        pos0 = pos[h]

        # 増やす方向に探索
        now0 = 0
        while True:
            if pos[h] == T:  # 終了条件
                break
            if (pos[h] + 1) % N  == pos[1 - h]:  # 衝突する時
                now0 = INF
                break
            pos[h] = (pos[h] + 1) % N
            now0 += 1

        pos[h] = pos0

        # 減らす方向に探索
        now1 = 0
        while True:
            if pos[h] == T:  # 終了条件
                break
            if (pos[h] + N - 1) % N == pos[1 - h]:  # 衝突する時
                now1 = INF
                break
            pos[h] = (pos[h] + N - 1) % N
            now1 += 1

        # 次へ
        pos[h] = T
        now = min(now0, now1)
        ans += now

    print(ans)


if __name__ == "__main__":
    main()
