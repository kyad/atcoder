# https://atcoder.jp/contests/s8pc-3/tasks/s8pc_3_b
# Python3: TLE
# PyPy3: AC

import copy
import sys

def solve(board, K, sy, sx):
    H = len(board)
    W = len(board[0]) - 1
    board[sy][sx] = 0
    i = 0
    ans = 0
    while True:
        # Drop
        for x in range(W):
            y0 = H - 1
            for y in range(H - 1, -1, -1):
                while board[y0][x] == 0:
                    y0 -= 1
                    if y0 < 0:
                        break
                if y0 < 0:
                    board[y][x] = 0
                else:
                    board[y][x] = board[y0][x]
                    y0 -= 1
        # Erase
        point = 0
        for y in range(H):
            start = -1
            prev = -1
            for x in range(W + 1):
                if prev != board[y][x]:
                    l = x - start
                    if l >= K and prev >= 0:
                        point += 2 ** i * prev * l
                        for xx in range(start, x):
                            board[y][xx] = 0
                    start = x
                    prev = board[y][x]
        if point == 0:
            break
        ans += point
        i += 1
    return ans
        
def main():
    H, W, K = map(int, sys.stdin.readline().split())
    board = [[-1] * (W + 1) for y in range(H)]
    for y in range(H):
        line = list(input())
        for x in range(W):
            board[y][x] = ord(line[x]) - ord('0')
        board[y][W] = -1
    ans = 0
    for sy in range(H):
        for sx in range(W):
            ans = max(ans, solve(copy.deepcopy(board), K, sy, sx))
    print(ans)

if __name__ == '__main__':
    main()
